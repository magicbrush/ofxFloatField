#include "ofxFF_Add.h"


ofxFF_Add::ofxFF_Add( ofPtr<ofxFloatField> F0, ofPtr<ofxFloatField> F1 )
{
	Fields.push_back(F0);
	Fields.push_back(F1);
}

ofxFF_Add::ofxFF_Add( vector<ofPtr<ofxFloatField> > Fs )
{
	Fields = Fs;
}

ofxFF_Add::~ofxFF_Add(void)
{

}

float ofxFF_Add::_get( ofPoint P )
{
	float s(0.0f);
	vector<ofPtr<ofxFloatField> >::iterator it;
	for(it = Fields.begin();it<Fields.end();it++)
	{
		s += (*it)->get(P);
	}	
	return s;
}

void ofxFF_Add::addToParamGroup( ofParameterGroup& G )
{	
	vector<ofPtr<ofxFloatField> >::iterator it;
	for(it = Fields.begin();it<Fields.end();it++)
	{
		G.add((*it)->getParamGroup());
	}	
	G.setName("ofxFF_Add_ParamGroup");
}

void ofxFF_Add::addField( ofPtr<ofxFloatField> F )
{
	Fields.push_back(F);
}
