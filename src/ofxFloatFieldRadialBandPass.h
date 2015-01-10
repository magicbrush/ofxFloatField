#pragma once
#ifndef __OFXFLOATFIELDRADIALBANDPASS_H__
#define __OFXFLOATFIELDRADIALBANDPASS_H__

#include "ofxfloatfield.h"

class ofxFloatFieldRadialBandPass :
	public ofxFloatField
{
public:
	ofxFloatFieldRadialBandPass(void);
	virtual ~ofxFloatFieldRadialBandPass(void);

	ofParameter<ofVec2f> getBand() const { return Band; }
	void setBand(ofParameter<ofVec2f> val) { Band = val; }

protected:
	virtual float _get( ofPoint P );
	virtual void addToParamGroup( ofParameterGroup& G );

private:
	ofParameter<ofVec2f> Band;
	
};

#endif

