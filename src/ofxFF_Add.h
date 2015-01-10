#pragma once
#ifndef __OFXFF_ADD_H__
#define __OFXFF_ADD_H__ 

#include "ofxfloatfield.h"

class ofxFF_Add :
	public ofxFloatField
{
public:
	ofxFF_Add(
		ofPtr<ofxFloatField> F0, 
		ofPtr<ofxFloatField> F1);
	ofxFF_Add(vector<ofPtr<ofxFloatField> > Fs);
	virtual ~ofxFF_Add(void);

	void addField(ofPtr<ofxFloatField> F);
protected:
	virtual float _get( ofPoint P );
	virtual void addToParamGroup( ofParameterGroup& G );

private:
	vector<ofPtr<ofxFloatField> > Fields;

};

#endif

