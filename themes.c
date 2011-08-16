/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <sys/reboot.h>

#include "themes.h"
#include "settings_file.h"
#include "extra-functions.h"

#define THEME_REBOOT_RECOVERY 0
#define TW_THEME              1
#define CM_THEME              2
#define RED_THEME             3
#define GOOGLE_THEME          4
#define JF_THEME              5
#define HTC_THEME             6
#define FABULOUS_THEME        7
#define PURPLE_SHIFT          8
#define GREYBALLER_THEME      9
#define TRIPPY_THEME	      10
#define SHIFTY_BASTARD	      11
#define THEMES_BACK           12

char* checkTheme(int tw_theme)
{
	int isVal;
	int isTrue = 0;
	char* tmp_set = (char*)malloc(40);
	switch (tw_theme)
	{
		case TW_THEME:
			strcpy(tmp_set, "[ ] Team Win Theme (Default)");
			break;
		case CM_THEME:
			strcpy(tmp_set, "[ ] CyanogenMod Theme");
			break;
		case RED_THEME:
			strcpy(tmp_set, "[ ] Red Rum Theme");
			break;
		case GOOGLE_THEME:
			strcpy(tmp_set, "[ ] Google Theme");
			break;
		case JF_THEME:
			strcpy(tmp_set, "[ ] JesusFreke Theme (oldschool)");
			break;
		case HTC_THEME:
			strcpy(tmp_set, "[ ] HTC Theme");
			break;
		case FABULOUS_THEME:
			strcpy(tmp_set, "[ ] Fabulous Theme");
			break;
		case PURPLE_SHIFT:
			strcpy(tmp_set, "[ ] Purple Shift");
			break;
		case GREYBALLER_THEME:
			strcpy(tmp_set, "[ ] Greyballer");
			break;
		case TRIPPY_THEME:
			strcpy(tmp_set, "[ ] Trippy");
			break;
		case SHIFTY_BASTARD:
			strcpy(tmp_set, "[ ] Shifty Bastard");
			break;
	}
	sscanf(tw_color_theme_val,"%d",&isVal);
	if (isVal == tw_theme - 1)
	{
		tmp_set[1] = 'x';
	}
	return tmp_set;
}

void twrp_themes_menu()
{
    	static char* MENU_THEMES_HEADERS[] = { "Recovery Color Chooser",
                                               NULL };
    
	char* MENU_THEMES[] = { "[REBOOT AND APPLY THEME]",
				checkTheme(TW_THEME),
				checkTheme(CM_THEME),
				checkTheme(RED_THEME),
				checkTheme(GOOGLE_THEME),
				checkTheme(JF_THEME),
				checkTheme(HTC_THEME),
				checkTheme(FABULOUS_THEME),
				checkTheme(PURPLE_SHIFT),
				checkTheme(GREYBALLER_THEME),
				checkTheme(TRIPPY_THEME),
				checkTheme(SHIFTY_BASTARD),
				"<-- Back To Recovery Settings",
				NULL };

    	char** headers = prepend_title(MENU_THEMES_HEADERS);
    
    	inc_menu_loc(THEMES_BACK);
    	for (;;)
    	{
        	int chosen_item = get_menu_selection(headers, MENU_THEMES, 0, 0);
        	switch (chosen_item)
        	{
            		case THEME_REBOOT_RECOVERY:
            			ensure_path_unmounted("/sdcard");
                		__reboot(LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART2, "recovery");
                		break;
            		case TW_THEME:
            			strcpy(tw_color_theme_val,"0");
                		break;
            		case CM_THEME:
            			strcpy(tw_color_theme_val,"1");
                		break;
            		case RED_THEME:
            			strcpy(tw_color_theme_val,"2");
                		break;
            		case GOOGLE_THEME:
            			strcpy(tw_color_theme_val,"3");
                		break;
            		case JF_THEME:
            			strcpy(tw_color_theme_val,"4");
                		break;
            		case HTC_THEME:
            			strcpy(tw_color_theme_val,"5");
                		break;
            		case FABULOUS_THEME:
            			strcpy(tw_color_theme_val,"6");
                		break;
	    		case PURPLE_SHIFT:
				strcpy(tw_color_theme_val,"7");
                		break;
	    		case GREYBALLER_THEME:
				strcpy(tw_color_theme_val,"8");
                		break;
	    		case TRIPPY_THEME:
				strcpy(tw_color_theme_val,"9");
                		break;
	    		case SHIFTY_BASTARD:
				strcpy(tw_color_theme_val,"10");
                		break;
            		case THEMES_BACK:
            			dec_menu_loc();
            			return;
        	}
        	if (go_home) {
        		dec_menu_loc();
	        	return;
	    	}
        	write_s_file();
        	break;
    	}
	ui_end_menu();
    	dec_menu_loc();
    	twrp_themes_menu();
}

void set_theme(char* tw_theme)
{
	if (strcmp(tw_theme,"0") == 0) // TEAMWIN THEME (default)
	{
		//HEADER_TEXT_COLOR
		htc.r = 0;
		htc.g = 255;
		htc.b = 0;
		htc.a = 255;

		//MENU_ITEM_COLOR
		mtc.r = 0;
		mtc.g = 255;
		mtc.b = 0;
		mtc.a = 255;

		//UI_PRINT_COLOR
		upc.r = 0;
		upc.g = 255;
		upc.b = 0;
		upc.a = 255;

		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 0;
		mihc.g = 255;
		mihc.b = 0;
		mihc.a = 255;

		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;

		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 0;
		mhebc.g = 255;
		mhebc.b = 0;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"1") == 0) // CM theme
	{
		htc.r = 61;
		htc.g = 233;
		htc.b = 255;
		htc.a = 255;

		mtc.r = 61;
		mtc.g = 233;
		mtc.b = 255;
		mtc.a = 255;

		upc.r = 61;
		upc.g = 233;
		upc.b = 255;
		upc.a = 255;

		mihc.r = 61;
		mihc.g = 233;
		mihc.b = 255;
		mihc.a = 255;

		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		
		mhebc.r = 61;
		mhebc.g = 233;
		mhebc.b = 255;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"2") == 0) // RED
	{
		htc.r = 255;
		htc.g = 0;
		htc.b = 0;
		htc.a = 255;

		mtc.r = 255;
		mtc.g = 0;
		mtc.b = 0;
		mtc.a = 255;

		upc.r = 255;
		upc.g = 0;
		upc.b = 0;
		upc.a = 255;

		mihc.r = 255;
		mihc.g = 0;
		mihc.b = 0;
		mihc.a = 255;

		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		
		mhebc.r = 255;
		mhebc.g = 0;
		mhebc.b = 0;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"3") == 0) // GOOGLE
	{
		//HEADER_TEXT_COLOR
		htc.r = 64;
		htc.g = 96;
		htc.b = 255;
		htc.a = 255;
		//MENU_ITEM_COLOR
		mtc.r = 64;
		mtc.g = 96;
		mtc.b = 255;
		mtc.a = 255;
		//UI_PRINT_COLOR
		upc.r = 64;
		upc.g = 96;
		upc.b = 255;
		upc.a = 255;
		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 64;
		mihc.g = 96;
		mihc.b = 255;
		mihc.a = 255;
		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 64;
		mhebc.g = 96;
		mhebc.b = 255;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"4") == 0) // JesusFreke
	{
		//HEADER_TEXT_COLOR
		htc.r = 25;
		htc.g = 45;
		htc.b = 255;
		htc.a = 255;
		//MENU_ITEM_COLOR
		mtc.r = 25;
		mtc.g = 45;
		mtc.b = 255;
		mtc.a = 255;
		//UI_PRINT_COLOR
		upc.r = 25;
		upc.g = 45;
		upc.b = 255;
		upc.a = 255;
		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 25;
		mihc.g = 45;
		mihc.b = 255;
		mihc.a = 255;
		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 25;
		mhebc.g = 45;
		mhebc.b = 255;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"5") == 0) // HTC
	{
		//HEADER_TEXT_COLOR
		htc.r = 153;
		htc.g = 153;
		htc.b = 153;
		htc.a = 255;
		//MENU_ITEM_COLOR
		mtc.r = 153;
		mtc.g = 153;
		mtc.b = 153;
		mtc.a = 255;
		//UI_PRINT_COLOR
		upc.r = 153;
		upc.g = 153;
		upc.b = 153;
		upc.a = 255;
		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 153;
		mihc.g = 153;
		mihc.b = 153;
		mihc.a = 255;
		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 153;
		mhebc.g = 153;
		mhebc.b = 153;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"6") == 0) // FABULOUS
	{
		//HEADER_TEXT_COLOR
		htc.r = 255;
		htc.g = 77;
		htc.b = 136;
		htc.a = 125;

		//MENU_ITEM_COLOR
		mtc.r = 255;
		mtc.g = 77;
		mtc.b = 136;
		mtc.a = 125;

		//UI_PRINT_COLOR
		upc.r = 255;
		upc.g = 77;
		upc.b = 136;
		upc.a = 125;

		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 255;
		mihc.g = 77;
		mihc.b = 136;
		mihc.a = 125;

		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;

		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 255; //195
		mhebc.g = 77; //255
		mhebc.b = 136; //77
		mhebc.a = 125;
	}
	if (strcmp(tw_theme,"7") == 0) // PURPLE SHIFT
	{
        	//HEADER_TEXT_COLOR
		htc.r = 140;
		htc.g = 0;
		htc.b = 255;
		htc.a = 255;

		//MENU_ITEM_COLOR
		mtc.r = 140;
		mtc.g = 0;
		mtc.b = 255;
		mtc.a = 255;

		//UI_PRINT_COLOR
		upc.r = 140;
		upc.g = 0;
		upc.b = 255;
		upc.a = 255;

		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 140;
		mihc.g = 0;
		mihc.b = 255;
		mihc.a = 255;

		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;

		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 140;
		mhebc.g = 0;
		mhebc.b = 255;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"8") == 0) // GREYBALLER
	{
        	//HEADER_TEXT_COLOR
		htc.r = 138;
		htc.g = 138;
		htc.b = 138;
		htc.a = 255;

		//MENU_ITEM_COLOR
		mtc.r = 138;
		mtc.g = 138;
		mtc.b = 138;
		mtc.a = 255;

		//UI_PRINT_COLOR
		upc.r = 138;
		upc.g = 138;
		upc.b = 138;
		upc.a = 255;

		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 138;
		mihc.g = 138;
		mihc.b = 138;
		mihc.a = 255;

		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;

		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 138;
		mhebc.g = 138;
		mhebc.b = 138;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"9") == 0) // TRIPPY
	{
		//HEADER_TEXT_COLOR
		htc.r = 136;
		htc.g = 77;
		htc.b = 255;
		htc.a = 125;

		//MENU_ITEM_COLOR
		mtc.r = 136;
		mtc.g = 77;
		mtc.b = 255;
		mtc.a = 125;

		//UI_PRINT_COLOR
		upc.r = 136;
		upc.g = 77;
		upc.b = 255;
		upc.a = 125;

		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 136;
		mihc.g = 77;
		mihc.b = 255;
		mihc.a = 125;

		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;

		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 136;
		mhebc.g = 77;
		mhebc.b = 255;
		mhebc.a = 125;
	}
	if (strcmp(tw_theme,"10") == 0) // SHIFTY BASTARD
	{
		//HEADER_TEXT_COLOR
		htc.r = 207;
		htc.g = 207;
		htc.b = 207;
		htc.a = 125;

		//MENU_ITEM_COLOR
		mtc.r = 207;
		mtc.g = 207;
		mtc.b = 207;
		mtc.a = 125;

		//UI_PRINT_COLOR
		upc.r = 207;
		upc.g = 207;
		upc.b = 207;
		upc.a = 125;

		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 207;
		mihc.g = 207;
		mihc.b = 207;
		mihc.a = 125;

		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;

		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 207;
		mhebc.g = 207;
		mhebc.b = 207;
		mhebc.a = 125;
	}
}
