#pragma once
#ifndef __OFXFF_MUL_H__
#define __OFXFF_MUL_H__ 

#include "ofxfloatfield.h"

class ofxFF_Mul :
	public ofxFloatField
{
public:
	ofxFF_Mul(
		ofPtr<ofxFloatField> F0, 
		ofPtr<ofxFloatField> F1);
	ofxFF_Mul(vector<ofPtr<ofxFloatField> > Fs);
	virtual ~ofxFF_Mul(void);

	void addField(ofPtr<ofxFloatField> F);
protected:
	virtual float _get( ofPoint P );
	virtual void addToParamGroup( ofParameterGroup& G );

private:
	vector<ofPtr<ofxFloatField> > Fields;

};

#endif

