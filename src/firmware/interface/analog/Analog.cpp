/*
    OpenDeck MIDI platform firmware
    Copyright (C) 2015-2017 Igor Petrovic

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Analog.h"
#include "../../board/Board.h"

const uint8_t disableCompare = 0b11111100;

Analog::Analog()
{
    //def const
}

void Analog::update()
{
    if (!board.analogDataAvailable())
        return;

    int16_t analogData;

    //check values
    for (int i=0; i<MAX_NUMBER_OF_ANALOG; i++)
    {
        analogData = board.getAnalogValue(i);

        //don't process component if it's not enabled
        if (!database.read(DB_BLOCK_ANALOG, analogEnabledSection, i))
            continue;

        if (database.read(DB_BLOCK_ANALOG, analogTypeSection, i) != aType_button)
        {
            #ifdef ENABLE_HYSTERESIS
            analogData = getHysteresisValue(i, analogData);
            #endif
            analogType_t type = (analogType_t)database.read(DB_BLOCK_ANALOG, analogTypeSection, i);

            switch(type)
            {
                case aType_potentiometer_cc:
                case aType_potentiometer_note:
                checkPotentiometerValue(i, analogData);
                break;

                case aType_fsr:
                checkFSRvalue(i, analogData);
                break;

                default:
                break;
            }
        }
        else
        {
            //read raw value
            analogData = board.getAnalogValue(i);

            if (analogData == -1)
            {
                continue;
            }

            bool state = analogData > DIGITAL_VALUE_THRESHOLD;
            buttons.processButton(i+MAX_NUMBER_OF_BUTTONS, state, false);
        }
    }

    board.continueADCreadout();
}

#ifdef ENABLE_HYSTERESIS
uint16_t Analog::getHysteresisValue(uint8_t analogID, uint16_t value)
{
    if (value > HYSTERESIS_THRESHOLD)
    {
        value += HYSTERESIS_ADDITION;

        if (value > 1023)
            return 1023;

        return value;
    }
    else
    {
        if (value < (HYSTERESIS_THRESHOLD-HYSTERESIS_ADDITION))
        {
            return value;
        }
        else
        {
            if (abs(lastAnalogueValue[analogID] - value) < HYSTERESIS_ADDITION)
            {
                //hysteresis still enabled
                value += HYSTERESIS_ADDITION;

                if (value > 1023)
                    return 1023;

                return value;
            }
            else
            {
                return value;
            }
        }
    }
}
#endif

void Analog::debounceReset(uint16_t index)
{
    lastAnalogueValue[index] = 0;

    uint8_t arrayIndex = index/8;
    uint8_t fsrIndex = index - 8*arrayIndex;

    BIT_CLEAR(fsrPressed[arrayIndex], fsrIndex);
}

Analog analog;