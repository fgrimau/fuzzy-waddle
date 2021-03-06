#ifndef notif_h
    #define notif_h

#include <SDL2/SDL_stdinc.h>
#include <iostream>

#include "widgets.hpp"

class Notification: public Widget{
    public:
        // Constructors
        Notification();
        ~Notification();

        // Operator
        Notification& operator=(const Notification&);

        // Setters
        void set_position(int, int);
        void set_text(std::string);
        void set_icon(SDL_Texture*);
        void set_lifetime(Uint16);
        void set_offset(int offset);

        void set_width(int);

        // Getters
        int get_height() const;

        bool is_alive() const;

        // Others
        int draw(Screen*) override;
        int update(SDL_Event*, Screen*) override;

        void init(Screen*, std::string font);

    private:
        std::string m_content;

        SDL_Rect m_position;
        int m_offset;

        SDL_Color m_progress_bar_color;
        SDL_Color m_text_color;

        SDL_Texture* m_background;
        SDL_Texture* m_text_texture;
        SDL_Texture* m_progress_bar;
        SDL_Texture* m_icon;

        Uint16 m_total_lifetime;   // Max 65536 ms
        Uint16 m_current_lifetime; // Max 65536 ms

        Uint8 m_alpha;
};

#endif
