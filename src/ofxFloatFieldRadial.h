#pragma once
#ifndef __OFXFLOATFIELDRADIAL_H__
#define __OFXFLOATFIELDRADIAL_H__
#include "ofxfloatfield.h"

class ofxFloatFieldRadial :
	public ofxFloatField
{
public:
	ofxFloatFieldRadial(void);
	virtual ~ofxFloatFieldRadial(void);

	ofParameter<float> getPower() const;
	void setPower(ofParameter<float> val);

protected:
	virtual float _get( ofPoint P );

	virtual void addToParamGroup( ofParameterGroup& G );

private:
	ofParameter<float> Power;
	
};

#endif

