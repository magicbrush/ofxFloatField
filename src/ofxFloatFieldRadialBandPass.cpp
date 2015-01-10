#include "ofxFloatFieldRadialBandPass.h"


ofxFloatFieldRadialBandPass::ofxFloatFieldRadialBandPass(void)
{
	Band.set("Band",
		ofVec2f(0.0f,1.0f),
		ofVec2f(0.0f,0.0f),
		ofVec2f(10000.0f,10000.0f));
}

ofxFloatFieldRadialBandPass::~ofxFloatFieldRadialBandPass(void)
{

}

float ofxFloatFieldRadialBandPass::_get( ofPoint P )
{
	float radius = P.length();
	ofVec2f B = Band;
	return ofInRange(radius,min(B.x,B.y),max(B.x,B.y));
}

void ofxFloatFieldRadialBandPass::addToParamGroup( ofParameterGroup& G )
{
	G.setName("ofxFloatFieldRadialBandPass_ParamGroup");
	G.add(Band);
}
