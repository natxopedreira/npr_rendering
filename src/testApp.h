#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofTrueTypeFont font;
		ofShader shader,shader8x8;
		ofVideoGrabber camara;
	ofVideoPlayer player;
		bool doShader;
		ofImage imaxe;
	
	float luminance1;
    float luminance2;
    float luminance3;
    float luminance4;
    float luminance5;
	
    int lineThickness;
    int lineDistance;
	
};

