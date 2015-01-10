#include "ofxFF_Mul.h"


ofxFF_Mul::ofxFF_Mul( ofPtr<ofxFloatField> F0, ofPtr<ofxFloatField> F1 )
{
	Fields.push_back(F0);
	Fields.push_back(F1);
}

ofxFF_Mul::ofxFF_Mul( vector<ofPtr<ofxFloatField> > Fs )
{
	Fields = Fs;
}

ofxFF_Mul::~ofxFF_Mul(void)
{

}

float ofxFF_Mul::_get( ofPoint P )
{
	float s(1.0f);
	vector<ofPtr<ofxFloatField> >::iterator it;
	for(it = Fields.begin();it<Fields.end();it++)
	{
		s *= (*it)->get(P);
	}	
	return s;
}

void ofxFF_Mul::addToParamGroup( ofParameterGroup& G )
{	
	vector<ofPtr<ofxFloatField> >::iterator it;
	for(it = Fields.begin();it<Fields.end();it++)
	{
		G.add((*it)->getParamGroup());
	}	
	G.setName("ofxFF_Mul_ParamGroup");
}

void ofxFF_Mul::addField( ofPtr<ofxFloatField> F )
{
	Fields.push_back(F);
}
