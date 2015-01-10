#include "ofxFloatFieldRadial.h"


ofxFloatFieldRadial::ofxFloatFieldRadial(void)
{
	Power.set("PowerOfRadius",1.0f,-10.0f,10.0f);
}

ofxFloatFieldRadial::~ofxFloatFieldRadial(void)
{

}

float ofxFloatFieldRadial::_get( ofPoint P )
{
	float radius = P.length();
	float v = pow(radius,Power);
	return v;
}

void ofxFloatFieldRadial::setPower( ofParameter<float> val )
{
	Power = val;
}

ofParameter<float> ofxFloatFieldRadial::getPower() const
{
	return Power;
}

void ofxFloatFieldRadial::addToParamGroup( ofParameterGroup& G )
{
	G.setName("ofxFloatFieldRadialParams");
	G.add(Power);
}
