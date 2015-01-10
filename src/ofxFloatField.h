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
	void setParentField(ofPtr<ofxFloatField> pFParent);
	ofParameterGroup getParamGroup();
	float get(ofPoint P);
	
	ofMatrix4x4 getPreTF() const;
	void setPreTF(ofMatrix4x4 val);
	ofParameter<float> getPostScale() const;
	void setPostScale(ofParameter<float> val);
	ofParameter<float> getPostPow() const { return PostPow; }
	void setPostPow(ofParameter<float> val) { PostPow = val; }

protected:
	virtual float _get(ofPoint P);
	virtual void addToParamGroup(ofParameterGroup& G);

private:
	ofPtr<ofxFloatField> FParent;
	ofMatrix4x4 PreTF;		
	ofParameter<float> PostScale;
	ofParameter<float> PostPow;	
	ofParameter<bool> PowBeforeScale;

	ofParameterGroup G;
};

#endif