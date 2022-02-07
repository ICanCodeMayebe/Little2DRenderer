#pragma once

#include "Event.h"

namespace lil{

    class KeyEvent : public Event{
        public:
            inline int GetKeyCode() { return m_keyCode; }

            void LogIt(){
                LIL_INFO("KeyEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }
            SET_EVENT_TYPE(EventType::None)

            SET_CATEGORY(EventCategory::Keyboard | EventCategory::Input)
        protected:
            KeyEvent(int keyCode) { m_keyCode = keyCode;}

            int m_keyCode;

    };

    class KeyDownEvent : public KeyEvent {
        public:
            KeyDownEvent(int keyCode, bool wasRepeated) 
            : m_wasRepeated(wasRepeated), KeyEvent(keyCode){

            }
            
            void LogIt(){
                LIL_INFO("KeyDownEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }

            SET_EVENT_TYPE(EventType::KeyDown)
            SET_CATEGORY(EventCategory::Keyboard | EventCategory::Input | EventCategory::Down)
            inline bool WasKeyDownRepeate() { return m_wasRepeated;}

        private:
            bool m_wasRepeated;
    };

    class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(int keycode) : KeyEvent(keycode){
            }

            void LogIt(){
                LIL_INFO("KeyPressedEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }
            SET_EVENT_TYPE(EventType::KeyPressed)
            SET_CATEGORY(EventCategory::Keyboard | EventCategory::Input | EventCategory::Press)
                
    };

    class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(int keycode) : KeyEvent(keycode){
            }

            void LogIt(){
                LIL_INFO("KeyReleasedEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }

            SET_EVENT_TYPE(EventType::KeyReleased)
            SET_CATEGORY(EventCategory::Keyboard | EventCategory::Input | EventCategory::Release)
    };
}