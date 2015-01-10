#pragma once
#ifndef __OFXFLOATFIELDRADIALSIN_H__
#define __OFXFLOATFIELDRADIALSIN_H__
#include "ofxfloatfield.h"

class ofxFloatFieldRadialSin :
	public ofxFloatField
{
public:
	ofxFloatFieldRadialSin(
		float amp=1.0f, 
		float freq=1.0f, 
		float phase=0.0f);
	~ofxFloatFieldRadialSin(void);

	ofParameter<float> getFreq() const;
	void setFreq(ofParameter<float> val);
	ofParameter<float> getPhase() const;
	void setPhase(ofParameter<float> val);
	ofParameter<float> getAmplitude() const;
	void setAmplitude(ofParameter<float> val);

protected:
	virtual float _get( ofPoint P );
	virtual void addToParamGroup( ofParameterGroup& G );

private:
	ofParameter<float> Amplitude;	
	ofParameter<float> Freq;	
	ofParameter<float> Phase;
	

};

#endif

