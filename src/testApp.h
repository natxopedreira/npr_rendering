#pragma once

#include "ofMain.h"
#include "ofxSimpleGuiToo.h"

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
		ofShader shader,shader8x8,hatch;
		ofVideoGrabber camara;
		ofVideoPlayer player;
		ofImage imaxe;
	
		/// vars para el hatch shader
	float m_ColorInfluenceLine;
	float m_ColorInfluencePaper;
	float m_FillValue;
	float m_Luminance1;
	float m_Luminance2;
	float m_Luminance3;
	float m_Luminance4;
	float m_Luminance5;
	float m_LineDistance;
	float m_LineThickness;	
	
	
};

