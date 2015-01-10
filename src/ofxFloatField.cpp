#include "ofxFloatField.h"

ofxFloatField::ofxFloatField( ofMatrix4x4 PrevMat, float PostScl )
{
	setPreTF(PrevMat);
	setPostScale(PostScl);

	PostScale.set("PostScale",1.0f,0.01f,100.0f);
	PostPow.set("PostPower",1.0f,-10.0f,10.0f);
	PowBeforeScale.set("PowerBeforeScale",true,false,true);

	G.setName("ofxFloatFieldParams");
}

ofxFloatField::~ofxFloatField()
{

}

float ofxFloatField::get( ofPoint P )
{
	ofPoint P1 = P*PreTF;
	float V;
	V = _get(P1);
	float V2;
	if(PowBeforeScale)
	{
		float Vt = pow(V,PostPow);
		V2 = Vt * PostScale;
	}
	else
	{
		float Vt = V*PostScale;
		V2 = pow(Vt,PostPow);
	}
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
	G.add(PostPow);
	G.add(PowBeforeScale);
	addToParamGroup(G);
	return G;
}

void ofxFloatField::addToParamGroup( ofParameterGroup& G )
{

}

float ofxFloatField::_get( ofPoint P )
{
	float v;
	if(FParent.use_count()>0)
	{
		v = FParent->get(P);
	}
	else
	{
		v = 1.0f;
	}	
	return 1.0f;
}

void ofxFloatField::setParentField( ofPtr<ofxFloatField> pFParent )
{
	FParent = pFParent;
}
