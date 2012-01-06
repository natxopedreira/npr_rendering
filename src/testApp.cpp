#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	
	player.loadMovie("loop640.mp4");
	player.play();
	
	imaxe.loadImage("piedra.jpg");
	shader.load("shaders/noise.vert", "shaders/noise.frag");
	shader8x8.load("shaders/bayermatrix.vert", "shaders/bayermatrix.frag");
	hatch.load("shaders/hatch.vert", "shaders/hatch.frag");
	
	gui.addTitle("crosshatching");
	gui.addSlider("ColorInfluenceLine", m_ColorInfluenceLine, 0.0, 1.0);
	gui.addSlider("ColorInfluencePaper", m_ColorInfluencePaper, 0.0, 1.0);
	gui.addSlider("FillValue", m_FillValue, 0.0, 1.0);
	gui.addSlider("Luminance1", m_Luminance1, 0.0, 1.0);
	gui.addSlider("Luminance2", m_Luminance2, 0.0, 1.0);
	gui.addSlider("Luminance3", m_Luminance3, 0.0, 1.0);
	gui.addSlider("Luminance4", m_Luminance4, 0.0, 1.0);
	gui.addSlider("Luminance5", m_Luminance5, 0.0, 1.0);
	gui.addSlider("LineDistance", m_LineDistance, 0.0, 10.0);
	gui.addSlider("LineThickness", m_LineThickness, 0.0, 10.0);
	gui.loadFromXML();
	gui.show();
	

	
}

//--------------------------------------------------------------
void testApp::update(){
	//camara.update();
	player.update();
	shader.setUniformTexture("sceneTex", player.getTextureReference(), 0);
	shader8x8.setUniformTexture("Tex0", player.getTextureReference(), 0);
	hatch.setUniformTexture("Tex0", player.getTextureReference(), 0);
	

	cout << m_LineThickness << endl;
	/*
	m_ColorInfluenceLine = 0.0;
	m_ColorInfluencePaper = 0.0;
	m_FillValue = 0.9;
	m_Luminance1 = 0.9;
	m_Luminance2 = 0.7;
	m_Luminance3 = 0.5;
	m_Luminance4 = 0.3;
	m_Luminance5 = 0.0;
	m_LineDistance = 4.0;
	m_LineThickness = 1.0;		
	*/
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(225);

	ofPushMatrix();
	shader.begin();
	player.draw(0, 0);
	shader.end();
	ofPopMatrix();
	
	player.draw(640, 0);
	
	ofPushMatrix();
	ofTranslate(0, 360,0);
	shader8x8.begin();
	player.draw(0, 0);
	shader8x8.end();
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(640, 360,0);
	hatch.begin();
	hatch.setUniform1f("m_ColorInfluenceLine", m_ColorInfluenceLine);
	hatch.setUniform1f("m_ColorInfluencePaper", m_ColorInfluencePaper);
	hatch.setUniform1f("m_FillValue", m_FillValue);
	hatch.setUniform1f("m_Luminance1", m_Luminance1);
	hatch.setUniform1f("m_Luminance2", m_Luminance2);
	hatch.setUniform1f("m_Luminance3", m_Luminance3);
	hatch.setUniform1f("m_Luminance4", m_Luminance4);
	hatch.setUniform1f("m_Luminance5", m_Luminance5);
	hatch.setUniform1f("m_LineDistance", m_LineDistance);
	hatch.setUniform1f("m_LineThickness", m_LineThickness);
	player.draw(0, 0);
	hatch.end();
	ofPopMatrix();
	
	gui.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

