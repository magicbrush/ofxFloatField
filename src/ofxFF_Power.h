#pragma once
#ifndef __OFXFF_POWER_H__
#define __OFXFF_POWER_H__

#include "ofxfloatfield.h"
class ofxFF_Power :
	public ofxFloatField
{
public:
	ofxFF_Power(ofPtr<ofxFloatField> fBase);
	virtual ~ofxFF_Power(void);

protected:
	virtual float _get( ofPoint P );
	virtual void addToParamGroup( ofParameterGroup& G );

private:



};

#endif
