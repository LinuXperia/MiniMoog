/*
  ==============================================================================

    OutputPanel.h
    Created: 21 Mar 2019 6:44:28pm
    Author:  Benjamin Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../buttons/FlipSwitch.h"

//==============================================================================
/*
*/
class OutputPanel    : public Component
{
public:
    OutputPanel()
    {
        setSize(width, height);
        addAndMakeVisible(flip1);
        
        knobFont.setTypefaceName("Futura");
        knobFont.setHeight(12.0f);
        panelFont.setTypefaceName("Futura");
        panelFont.setHeight(28.0f);

    }

    ~OutputPanel()
    {
    }

    void paint (Graphics& g) override
    {
        area = Rectangle<int>(0, 0, width, height);
        g.setColour(Colours::black);
        g.fillRect(area);
        g.setColour(Colours::white);
        g.setFont(panelFont);
        g.drawText("OUTPUT", area, Justification::centredBottom, true);
        
        g.drawLine(0, 0, width, 0, lineThickness);
        g.drawLine(width, 0, width, height, lineThickness);
        g.drawLine(width, height, 0, height, lineThickness);
        g.drawLine(0, height, 0, 0, lineThickness);
    }

    void resized() override
    {
        area = Rectangle<int>(0, 0, width, height);
        flip1.setBounds(area);
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    Rectangle<int> area;
    FlipSwitch flip1;
    
    float lineThickness = 3.0f;
    
    int height = 350;
    int width = 150;
    int knobBorder = 5;
    int leftKnobOffset = 10;
    
    Font panelFont;
    Font knobFont;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputPanel)
};