#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	camara.initGrabber(640, 480);
	player.loadMovie("lucas.mov");
	player.play();
	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
	imaxe.loadImage("piedra.jpg");
	shader.load("shaders/noise.vert", "shaders/noise.frag");
	
	shader8x8.load("shaders/bayermatrix.vert", "shaders/bayermatrix.frag");
}

//--------------------------------------------------------------
void testApp::update(){
	//camara.update();
	player.update();
	shader.setUniformTexture("sceneTex", player.getTextureReference(), 0);
	shader8x8.setUniformTexture("Tex0", player.getTextureReference(), 0);
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

