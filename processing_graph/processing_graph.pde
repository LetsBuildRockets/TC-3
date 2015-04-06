
import processing.serial.*;

Serial myPort;        // The serial port
int xPos[] = {1, 1};         // horizontal position of the graph
float last[] = {0, 0};
void setup () {
  // set the window size:
  size(1000, 300);        

  // List all the available serial ports

  println(Serial.list());
  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[1], 9600);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
  background(230);
  strokeWeight(4);
}
void draw () {
  // everything happens in the serialEvent()
  //saveFrame();
}

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString[] = myPort.readStringUntil('\n').trim().split(":");
  if (inString != null) {
    int iden = int(inString[0]);
    float value = float(inString[1]);
    if(iden == 1) 
    println((value-1.25)/.005);
    value = map(value, 0, 5, 0, height);
    // draw the line:
    if(iden == 0) stroke(100, 20, 220, 100);
    if(iden == 1) stroke(20, 20, 220, 100);
    line(xPos[iden], height - last[iden], xPos[iden], height - value);

    last[iden] = value;
    // at the edge of the screen, go back to the beginning:
    if (xPos[iden] >= width) {
      xPos[iden] = 0;
      background(230);
    }
    else {
      // increment the horizontal position:
      xPos[iden]++;
    }
  }
}

