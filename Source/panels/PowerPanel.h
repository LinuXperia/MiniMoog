/*
  ==============================================================================

    PowerPanel.h
    Created: 21 Mar 2019 6:47:59pm
    Author:  Benjamin Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class PowerPanel    : public Component
{
public:
    PowerPanel()
    {
        setSize(width, height);
        
        knobFont.setTypefaceName("Futura");
        knobFont.setHeight(12.0f);
        panelFont.setTypefaceName("Futura");
        panelFont.setHeight(28.0f);
        panelFont.setExtraKerningFactor(0.075);

    }

    ~PowerPanel()
    {
    }

    void paint (Graphics& g) override
    {
        area = Rectangle<int>(0, 0, width, height);
        g.setColour(Colours::black);
        g.fillRect(area);
        g.setColour(Colours::white);
        g.setFont(panelFont);
        //g.drawText("OSCILLATOR BANK", area, Justification::centredBottom, true);
        
        g.drawLine(0, 0, width, 0, lineThickness);
        g.drawLine(width, 0, width, height, lineThickness);
        g.drawLine(width, height, 0, height, lineThickness);
        g.drawLine(0, height, 0, 0, lineThickness);
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    Rectangle<int> area;
    
    float lineThickness = 3.0f;
    
    int height = 350;
    int width = 75;
    int knobBorder = 5;
    int leftKnobOffset = 10;
    
    Font panelFont;
    Font knobFont;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PowerPanel)
};
