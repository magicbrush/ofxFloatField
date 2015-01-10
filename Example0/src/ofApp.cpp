#include "ofApp.h"
#include "ofxFloatField.h"
#include "ofxFloatFieldRadial.h"
#include "ofxFloatFieldRadialSin.h"
#include "ofxFloatFieldRadialBandPass.h"

//--------------------------------------------------------------
void ofApp::setup(){

	FF.reset(new ofxFloatFieldRadial);

	TF.scale(ofVec3f(350.0f,350.0f,1.0f));
	TF.translate(ofGetWidth()/2,ofGetHeight()/2,0);
	
	P.setup("GUI");
	initGUI();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofPushMatrix();
	ofMultMatrix(TF);
	float x = -1.0f;
	float y = -1.0f;
	for(float x=-1.0f;x<1.0f;x+=0.1f)
	{
		for(float y=-1.0f;y<1.0f;y+=0.1f)
		{
			ofVec3f P(x,y,0);
			float F = FF->get(P);
			ofPushStyle();
			//ofFloatColor C(0.5f*x+1.0f, 0.5f*y+1.0f,0);
			//ofSetColor(C);
			ofCircle(P,0.01f*F);
			ofPopStyle();
		}
	}
	ofPopMatrix();

	P.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if(OF_KEY_F1 ==key)
	{
		FF.reset(new ofxFloatFieldRadial);
		initGUI();
	}
	else if(OF_KEY_F2==key)
	{
		FF.reset(new ofxFloatFieldRadialSin);
		initGUI();
	}
	else if(OF_KEY_F3==key)
	{
		FF.reset(new ofxFloatFieldRadialBandPass);
		initGUI();
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::initGUI()
{
	P.clear();
	P.setPosition(0,0);

	ofParameterGroup G = FF->getParamGroup();
	P.add(G);
}
