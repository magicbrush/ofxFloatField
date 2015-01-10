#include "ofxFloatFieldRadialSin.h"


ofxFloatFieldRadialSin::ofxFloatFieldRadialSin( 
	float amp/*=1.0f*/, 
	float freq/*=1.0f*/, 
	float phase/*=0.0f*/ )
{
	Amplitude.set("Amplitude",amp,0.0f,100.0f);
	Freq.set("Frequency",freq,0.0f,100.0f);
	Phase.set("Phase",phase,0.0f,2.0f*PI);
}

ofxFloatFieldRadialSin::~ofxFloatFieldRadialSin( void )
{

}

float ofxFloatFieldRadialSin::_get( ofPoint P )
{
	float radius = P.length();
	float a,f,p;
	a = Amplitude;
	f = Freq;
	p = Phase;
	float v = a* sin(f*radius + p);
	return v;
}

void ofxFloatFieldRadialSin::addToParamGroup( ofParameterGroup& G )
{
	G.setName("ofxFloatFieldRadialSinParamGroup");
	G.add(Amplitude);
	G.add(Freq);
	G.add(Phase);
}

void ofxFloatFieldRadialSin::setPhase( ofParameter<float> val )
{
	Phase = val;
}

ofParameter<float> ofxFloatFieldRadialSin::getPhase() const
{
	return Phase;
}

void ofxFloatFieldRadialSin::setFreq( ofParameter<float> val )
{
	Freq = val;
}

ofParameter<float> ofxFloatFieldRadialSin::getFreq() const
{
	return Freq;
}

void ofxFloatFieldRadialSin::setAmplitude( ofParameter<float> val )
{
	Amplitude = val;
}

ofParameter<float> ofxFloatFieldRadialSin::getAmplitude() const
{
	return Amplitude;
}
