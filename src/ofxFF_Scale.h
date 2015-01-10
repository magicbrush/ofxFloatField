#pragma once
#ifndef __OFXFLOATFIELD_SCALE_H__
#define __OFXFLOATFIELD_SCALE_H__

#include "ofxfloatfield.h"
class ofxFF_Scale :
	public ofxFloatField
{
public:
	ofxFF_Scale(ofPtr<ofxFloatField> fBase);
	virtual ~ofxFF_Scale(void);

protected:
	virtual float _get( ofPoint P );
	virtual void addToParamGroup( ofParameterGroup& G );

private:
	ofPtr<ofxFloatField> FFBase;

};

#endif
