#include "ofxFF_Scale.h"


ofxFF_Scale::ofxFF_Scale( ofPtr<ofxFloatField> fBase )
{
	FFBase = fBase;
}

ofxFF_Scale::~ofxFF_Scale(void)
{

}

float ofxFF_Scale::_get( ofPoint P )
{
	float v = FFBase->get(P);
	return v;
}

void ofxFF_Scale::addToParamGroup( ofParameterGroup& G )
{
	G.setName("ofxFF_Scale_ParamGroup");
}
