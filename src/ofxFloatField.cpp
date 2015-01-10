#include "ofxFloatField.h"

ofxFloatField::ofxFloatField( ofMatrix4x4 PrevMat, float PostScl )
{
	setPreTF(PrevMat);
	setPostScale(PostScl);

	PostScale.set("PostScale",1.0f,0.01f,100.0f);

	G.setName("ofxFloatFieldParams");
}

ofxFloatField::~ofxFloatField()
{

}

float ofxFloatField::get( ofPoint P )
{
	ofPoint P1 = P*PreTF;
	float V = _get(P1);
	float V2 = V*PostScale;
	return V2;
}

void ofxFloatField::setPreTF( ofMatrix4x4 val )
{
	PreTF = val;
}

ofMatrix4x4 ofxFloatField::getPreTF() const
{
	return PreTF;
}

void ofxFloatField::setPostScale( ofParameter<float> val )
{
	PostScale = val;
}

ofParameter<float> ofxFloatField::getPostScale() const
{
	return PostScale;
}

ofParameterGroup ofxFloatField::getParamGroup()
{
	G.add(PostScale);
	addToParamGroup(G);
	return G;
}

void ofxFloatField::addToParamGroup( ofParameterGroup& G )
{

}
