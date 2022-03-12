#include <MozziGuts.h>
#include <Sample.h>

#include <samples/bamboo/bamboo_00_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_01_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_02_2048_int8.h> // wavetable data
#include "chirp.h" // wavetable data
#include "clap.h" // wavetable data
#include "cowbell.h" // wavetable data
#include "hihat.h" // wavetable data
#include "kick.h" // wavetable data
#include "snare.h" // wavetable data
#include <EventDelay.h>
#include <mozzi_rand.h>

#define CONTROL_RATE 128
#define XX true,
#define __ false,
#define CELLS_PER_SAMPLE 2048

// Bank of sample
// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aBamboo0(BAMBOO_00_2048_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aBamboo1(BAMBOO_01_2048_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aBamboo2(BAMBOO_02_2048_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aChirp(CHIRP_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aClap(CLAP_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aCowbell(COWBELL_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aKick(KICK_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aHiHat(HIHAT_DATA);
Sample <CELLS_PER_SAMPLE, AUDIO_RATE>aSnare(SNARE_DATA);

Sample <CELLS_PER_SAMPLE, AUDIO_RATE> *sample1 = &aKick;
Sample <CELLS_PER_SAMPLE, AUDIO_RATE> *sample2 = &aSnare;
Sample <CELLS_PER_SAMPLE, AUDIO_RATE> *sample3 = &aHiHat;

// for scheduling audio gain changes
EventDelay kTriggerDelay;

unsigned int tempoMs = 111;
const byte MAX_STEP_COUNT = 16;

byte cursor1 = 0;
byte cursor2 = 0;
byte cursor3 = 0;

// TODO
// https://diyelectromusic.wordpress.com/2021/06/22/arduino-mozzi-sample-drum-machine/

// the setup function runs once when you press reset or power the board
void setup() {
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
  aClap.setFreq((float) CLAP_SAMPLERATE / (float) CELLS_PER_SAMPLE); // play at the speed it was recorded
  aCowbell.setFreq((float) COWBELL_SAMPLERATE / (float) CELLS_PER_SAMPLE); // play at the speed it was recorded
  aHiHat.setFreq((float) HIHAT_SAMPLERATE / (float) CELLS_PER_SAMPLE); // play at the speed it was recorded
  aKick.setFreq((float) KICK_SAMPLERATE / (float) CELLS_PER_SAMPLE); // play at the speed it was recorded
  aSnare.setFreq((float) SNARE_SAMPLERATE / (float) CELLS_PER_SAMPLE); // play at the speed it was recorded

  kTriggerDelay.set(10); // countdown ms, within resolution of CONTROL_RATE
}


bool shouldPlay(byte steps, byte beats, byte i) {
  float divisor = ((float)beats / (float)steps);
  
  bool shouldPlay;
  if (i == 0) {
    shouldPlay = (beats != 0);
  } else {
    byte score = i * divisor;
    byte prevScore = (i - 1) * divisor;
    shouldPlay = (score > prevScore);
  }

  return shouldPlay;
}

void updateControl(){
  // if the sequencer is not running, take no action...
  if (digitalRead(2) == LOW) {
    return;
  }

  // select the right samples for each voice
  if (digitalRead(7) == LOW) {
    sample1 = &aChirp;
  } else if (digitalRead(8) == LOW) {
    sample1 = &aKick;
  } else {
    sample1 = &aBamboo0;
  }

  if (digitalRead(5) == LOW) {
    sample2 = &aBamboo1;
  } else if (digitalRead(6) == LOW) {
    sample2 = &aSnare;
  } else {
    sample2 = &aClap;
  }

  if (digitalRead(3) == LOW) {
    sample3 = &aBamboo2;
  } else if (digitalRead(4) == LOW) {
    sample3 = &aCowbell;
  } else {
    sample3 = &aHiHat;
  }

  // read the step lengths and beat densities
  byte steps1 = (byte) map(mozziAnalogRead(5), 0, 1023, 1, MAX_STEP_COUNT);
  byte beats1 = (byte) map(mozziAnalogRead(1), 0, 1023, 0, steps1);
  byte steps2 = (byte) map(mozziAnalogRead(6), 0, 1023, 1, MAX_STEP_COUNT);
  byte beats2 = (byte) map(mozziAnalogRead(2), 0, 1023, 0, steps2);
  byte steps3 = (byte) map(mozziAnalogRead(7), 0, 1023, 1, MAX_STEP_COUNT);
  byte beats3 = (byte) map(mozziAnalogRead(3), 0, 1023, 0, steps3);
  
  if(kTriggerDelay.ready()){
    if (cursor1 >= steps1) {
      cursor1 = 0;
    }
    if (cursor2 >= steps2) {
      cursor2 = 0;
    }
    if (cursor3 >= steps3) {
      cursor3 = 0;
    }
    
    if(shouldPlay(steps1, beats1, cursor1)) {
      (*sample1).start();
    }
    if(shouldPlay(steps2, beats2, cursor2)) {
      (*sample2).start();
    }
    if(shouldPlay(steps3, beats3, cursor3)) {
      (*sample3).start();
    }

    cursor1++;
    cursor2++;
    cursor3++;

    // tempo read
    kTriggerDelay.start(map(mozziAnalogRead(4), 0, 1023, 300, 50));
  }
}

int updateAudio(){
  // sum together the playing samples
  int asig= (int)
    ((long) (*sample1).next()*255 +
      (*sample2).next()*255 +
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
