#include <MozziGuts.h>
#include <Sample.h>

#include <samples/bamboo/bamboo_00_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_01_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_02_2048_int8.h> // wavetable data
#include "chirp.h" // wavetable data
#include <EventDelay.h>
#include <mozzi_rand.h>

#define CONTROL_RATE 128
#define XX true,
#define OO false,
#define CELLS_PER_SAMPLE 2048

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aBamboo0(BAMBOO_00_2048_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aBamboo1(BAMBOO_01_2048_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aBamboo2(BAMBOO_02_2048_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aChirp(CHIRP_DATA);

Sample <CELLS_PER_SAMPLE, AUDIO_RATE> *sample3 = &aChirp;

// for scheduling audio gain changes
EventDelay kTriggerDelay;

unsigned int tempoMs = 111;
const byte PATTERN_COUNT = 8;
const byte MAX_STEP_COUNT = 16;

const bool patterns[PATTERN_COUNT][MAX_STEP_COUNT] = {
  { OO OO OO OO OO OO OO OO OO OO OO OO OO OO OO OO },  
  { XX OO OO OO OO OO OO OO XX OO XX OO OO OO OO OO },
  { XX OO OO OO OO OO OO OO XX XX XX OO OO OO OO XX },
  { XX XX XX OO OO OO OO OO XX OO XX OO OO OO XX OO },
  { XX XX XX XX XX XX XX OO XX XX XX XX XX XX XX OO },
  { XX OO OO XX XX OO OO OO XX OO XX OO XX XX OO OO },
  { XX OO XX OO XX OO XX OO XX OO XX OO XX OO XX OO },
  { XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX },
};
byte pattern1 = 0;
byte pattern1Length = 16;
byte pattern1Beat = 0;

byte pattern2 = 0;
byte pattern2Length = 16;
byte pattern2Beat = 5;

byte pattern3 = 0;
byte pattern3Length = 16;
byte pattern3Beat = 9;

// TODO
// https://diyelectromusic.wordpress.com/2021/06/22/arduino-mozzi-sample-drum-machine/

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, OUTPUT);

  startMozzi();

  aBamboo0.setFreq((float) BAMBOO_00_2048_SAMPLERATE / (float) CELLS_PER_SAMPLE); // play at the speed it was recorded at
  aBamboo1.setFreq((float) BAMBOO_01_2048_SAMPLERATE / (float) CELLS_PER_SAMPLE);
  aBamboo2.setFreq((float) BAMBOO_02_2048_SAMPLERATE / (float) CELLS_PER_SAMPLE);
  aChirp.setFreq((float) CHIRP_SAMPLERATE / (float) CELLS_PER_SAMPLE); // play at the speed it was recorded
  
  kTriggerDelay.set(10); // countdown ms, within resolution of CONTROL_RATE
}

void updateControl(){
  // if the sequencer is not running...
  if (digitalRead(2) == LOW) {
    return;
  }

  pattern1 = (byte) map(mozziAnalogRead(1), 0, 1023, 0, (PATTERN_COUNT-1));
  pattern1Length = (byte) map(mozziAnalogRead(5), 0, 1023, 0, MAX_STEP_COUNT);
  pattern2 = (byte) map(mozziAnalogRead(2), 0, 1023, 0, (PATTERN_COUNT-1));
  pattern2Length = (byte) map(mozziAnalogRead(6), 0, 1023, 0, MAX_STEP_COUNT);
  pattern3 = (byte) map(mozziAnalogRead(3), 0, 1023, 0, (PATTERN_COUNT-1));
  pattern3Length = (byte) map(mozziAnalogRead(7), 0, 1023, 0, MAX_STEP_COUNT);
  
  if(kTriggerDelay.ready()){    
    if (patterns[pattern1][pattern1Beat]) {
      aBamboo0.start();
    }
    if (patterns[pattern2][pattern2Beat]) {
      aBamboo1.start();
    }
    if (patterns[pattern3][pattern3Beat]) {
      (*sample3).start();
    }

    if (++pattern1Beat >= pattern1Length) {
      pattern1Beat = 0;
    }
    if (++pattern2Beat >= pattern2Length) {
      pattern2Beat = 0;
    }
    if (++pattern3Beat >= pattern3Length) {
      pattern3Beat = 0;
    }

    // tempo read
    kTriggerDelay.start(map(mozziAnalogRead(4), 0, 1023, 300, 50));
  }
}

// TODO pointer to the current sample in each slot
int updateAudio(){
  // sum together the playing samples
  int asig= (int)
    ((long) aBamboo0.next()*255 +
      aBamboo1.next()*255 +
      (*sample3).next()*255)>>4;
  
  //clip to keep audio loud but still in range
  if (asig > 243) {
    asig = 243;
  }
  else if (asig < -244) {
    asig = -244;
  }
  return asig;
}


// the loop function runs over and over again forever
void loop() {
  audioHook();
}
