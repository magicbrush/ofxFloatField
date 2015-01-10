#pragma once
#ifndef __OFXFLOATFIELD_H__
#define __OFXFLOATFIELD_H__

#include "ofMain.h"

class ofxFloatField
{
public:
	ofxFloatField(
		ofMatrix4x4 PrevMat = ofMatrix4x4(), 
		float PostScl = 1.0f);
	virtual ~ofxFloatField();
	ofParameterGroup getParamGroup();
	float get(ofPoint P);
	
	ofMatrix4x4 getPreTF() const;
	void setPreTF(ofMatrix4x4 val);
	ofParameter<float> getPostScale() const;
	void setPostScale(ofParameter<float> val);

protected:
	virtual float _get(ofPoint P)=0;
	virtual void addToParamGroup(ofParameterGroup& G);

private:
	ofMatrix4x4 PreTF;		
	ofParameter<float> PostScale;
	
	ofParameterGroup G;

};

#endif