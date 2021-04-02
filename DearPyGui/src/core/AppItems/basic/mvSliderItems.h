#pragma once
#include "mvTypeBases.h"
#include <string>
#include "mvModule_Core.h"

//-----------------------------------------------------------------------------
// Widget Index
//
//     * mvSliderFloat
//     * mvSliderFloat2
//     * mvSliderFloat3
//     * mvSliderFloat4
//     * mvSliderInt
//     * mvSliderInt2
//     * mvSliderInt3
//     * mvSliderInt4
//
//-----------------------------------------------------------------------------

namespace Marvel {

    //-----------------------------------------------------------------------------
    // mvSliderFloat
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderFloat, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Float, 1);
    class mvSliderFloat : public mvFloatPtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPITEM_TYPE(mvAppItemType::mvSliderFloat, add_slider_float)

        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_Text                ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_Bg                  ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_BgHovered           ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_BgActive            ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_Grab                , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_GrabActive          , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_Border              ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat_BorderShadow        ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_Rounding          , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_BorderSize        , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_PaddingX          , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_PaddingY          , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_InnerSpacingX     , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_InnerSpacingY     , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_GrabMinSize       , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat_GrabRounding      , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_Text,           mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_Bg,             mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_BgHovered,      mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_BgActive,		mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_Grab,           mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_GrabActive,     mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_Border,         mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat_BorderShadow,   mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_Rounding          , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_BorderSize        , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_PaddingX          , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_PaddingY          , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_InnerSpacingX     , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_InnerSpacingY     , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_GrabMinSize       ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat_GrabRounding      , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderFloat(const std::string& name, float default_value, const std::string& dataSource);
        
        void setEnabled(bool value) override;
        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;

    private:

        float               m_min = 0.0f;
        float               m_max = 100.0f;
        std::string         m_format = "%.3f";
        bool                m_vertical = false;
        ImGuiInputTextFlags m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags m_stor_flags = ImGuiSliderFlags_None;

    };

    //-----------------------------------------------------------------------------
    // mvSliderFloat2
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderFloat2, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Float2, 1);
    class mvSliderFloat2 : public mvFloat2PtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPITEM_TYPE(mvAppItemType::mvSliderFloat2, add_slider_float2)

        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_Text              ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_Bg                ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_BgHovered         ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_BgActive          ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_Grab              , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_GrabActive        , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_Border            ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat2_BorderShadow      ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_Rounding        , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_BorderSize      , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_PaddingX        , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_PaddingY        , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_InnerSpacingX   , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_InnerSpacingY   , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_GrabMinSize     , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat2_GrabRounding    , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_Text,          mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_Bg,            mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_BgHovered,		mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_BgActive,		mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_Grab,          mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_GrabActive,    mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_Border,        mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat2_BorderShadow,  mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_Rounding      , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_BorderSize    , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_PaddingX      , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_PaddingY      , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_InnerSpacingX , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_InnerSpacingY , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_GrabMinSize   ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat2_GrabRounding  , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderFloat2(const std::string& name, float* default_value, const std::string& dataSource);
        
        void setEnabled(bool value) override;

        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;

    private:

        float                   m_min = 0.0f;
        float                   m_max = 100.0f;
        std::string             m_format = "%.3f";
        ImGuiInputTextFlags     m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags     m_stor_flags = ImGuiSliderFlags_None;
    };

    //-----------------------------------------------------------------------------
    // mvSliderFloat3
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderFloat3, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Float3, 1);
    class mvSliderFloat3 : public mvFloat3PtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPITEM_TYPE(mvAppItemType::mvSliderFloat3, add_slider_float3)

        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_Text              ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_Bg                ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_BgHovered         ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_BgActive          ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_Grab              , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_GrabActive        , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_Border            ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat3_BorderShadow      ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_Rounding        , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_BorderSize      , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_PaddingX        , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_PaddingY        , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_InnerSpacingX   , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_InnerSpacingY   , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_GrabMinSize     , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat3_GrabRounding    , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_Text,          mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_Bg,            mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_BgHovered,		mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_BgActive,		mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_Grab,          mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_GrabActive,    mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_Border,        mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat3_BorderShadow,  mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_Rounding     , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_BorderSize   , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_PaddingX     , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_PaddingY     , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_InnerSpacingX, 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_InnerSpacingY, 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_GrabMinSize  ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat3_GrabRounding , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderFloat3(const std::string& name, float* default_value, const std::string& dataSource);
        
        void setEnabled(bool value) override;
        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;
        
    private:

        float                   m_min = 0.0f;
        float                   m_max = 100.0f;
        std::string             m_format = "%.3f";
        ImGuiInputTextFlags     m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags     m_stor_flags = ImGuiSliderFlags_None;
    };
    
    //-----------------------------------------------------------------------------
    // mvSliderFloat4
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderFloat4, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Float4, 1);
    class mvSliderFloat4 : public mvFloat4PtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPITEM_TYPE(mvAppItemType::mvSliderFloat4, add_slider_float4)

        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_Text            ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_Bg              ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_BgHovered       ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_BgActive        ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_Grab            , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_GrabActive      , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_Border          ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderFloat4_BorderShadow    ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_Rounding      , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_BorderSize    , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_PaddingX      , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_PaddingY      , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_InnerSpacingX , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_InnerSpacingY , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_GrabMinSize   , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderFloat4_GrabRounding  , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_Text,          mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_Bg,            mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_BgHovered,     mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_BgActive,      mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_Grab,          mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_GrabActive,    mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_Border,        mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderFloat4_BorderShadow,  mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_Rounding     , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_BorderSize   , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_PaddingX     , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_PaddingY     , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_InnerSpacingX, 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_InnerSpacingY, 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_GrabMinSize  ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderFloat4_GrabRounding , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderFloat4(const std::string& name, float* default_value, const std::string& dataSource);
        
        void setEnabled(bool value) override;
        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;
        
    private:

        float                   m_min = 0.0f;
        float                   m_max = 100.0f;
        std::string             m_format = "%.3f";
        ImGuiInputTextFlags     m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags     m_stor_flags = ImGuiSliderFlags_None;
    };
     
    //-----------------------------------------------------------------------------
    // mvSliderInt
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderInt, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Int, 1);
    class mvSliderInt : public mvIntPtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);
 
        MV_APPITEM_TYPE(mvAppItemType::mvSliderInt, add_slider_int)

        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_Text                ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_Bg                  ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_BgHovered           ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_BgActive            ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_Grab                , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_GrabActive          , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_Border              ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt_BorderShadow        ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_Rounding          , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_BorderSize        , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_PaddingX          , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_PaddingY          , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_InnerSpacingX     , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_InnerSpacingY     , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_GrabMinSize       , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt_GrabRounding      , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_Text,             mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_Bg,               mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_BgHovered,        mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_BgActive,         mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_Grab,             mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_GrabActive,       mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_Border,           mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt_BorderShadow,     mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_Rounding        , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_BorderSize      , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_PaddingX        , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_PaddingY        , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_InnerSpacingX   , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_InnerSpacingY   , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_GrabMinSize     ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt_GrabRounding    , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderInt(const std::string& name, int default_value, const std::string& dataSource);
            
        void setEnabled(bool value) override;   
        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;
            
    private:

        int                 m_min = 0;
        int                 m_max = 100;
        std::string         m_format = "%d";
        bool                m_vertical = false;
        ImGuiInputTextFlags m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags m_stor_flags = ImGuiSliderFlags_None;
    };
        
    //-----------------------------------------------------------------------------
    // mvSliderInt2
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderInt2, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Int2, 1);
    class mvSliderInt2 : public mvInt2PtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPITEM_TYPE(mvAppItemType::mvSliderInt2, add_slider_int2)

        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_Text              ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_Bg                ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_BgHovered         ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_BgActive          ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_Grab              , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_GrabActive        , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_Border            ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt2_BorderShadow      ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_Rounding        , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_BorderSize      , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_PaddingX        , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_PaddingY        , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_InnerSpacingX   , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_InnerSpacingY   , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_GrabMinSize     , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt2_GrabRounding    , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_Text,         mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_Bg,           mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_BgHovered,    mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_BgActive,     mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_Grab,         mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_GrabActive,   mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_Border,       mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt2_BorderShadow, mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_Rounding       , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_BorderSize     , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_PaddingX       , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_PaddingY       , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_InnerSpacingX  , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_InnerSpacingY  , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_GrabMinSize    ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt2_GrabRounding   , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderInt2(const std::string& name, int* default_value, const std::string& dataSource);
        
        void setEnabled(bool value) override;
        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;
        
    private:

        int                 m_min = 0;
        int                 m_max = 100;
        std::string         m_format = "%d";
        ImGuiInputTextFlags m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags m_stor_flags = ImGuiSliderFlags_None;
    };
    
    //-----------------------------------------------------------------------------
    // mvSliderInt3
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderInt3, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Int3, 1);
    class mvSliderInt3 : public mvInt3PtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPITEM_TYPE(mvAppItemType::mvSliderInt3, add_slider_int3)

        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_Text              ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_Bg                ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_BgHovered         ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_BgActive          ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_Grab              , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_GrabActive        , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_Border            ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt3_BorderShadow      ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_Rounding        , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_BorderSize      , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_PaddingX        , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_PaddingY        , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_InnerSpacingX   , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_InnerSpacingY   , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_GrabMinSize     , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt3_GrabRounding    , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_Text,         mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_Bg,           mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_BgHovered,    mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_BgActive,     mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_Grab,         mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_GrabActive,   mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_Border,       mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt3_BorderShadow, mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_Rounding       , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_BorderSize     , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_PaddingX       , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_PaddingY       , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_InnerSpacingX  , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_InnerSpacingY  , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_GrabMinSize    ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt3_GrabRounding   , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderInt3(const std::string& name, int* default_value, const std::string& dataSource);
        
        void setEnabled(bool value) override;
        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;
        
    private:

        int                 m_min = 0;
        int                 m_max = 100;
        std::string         m_format = "%d";
        ImGuiInputTextFlags m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags m_stor_flags = ImGuiSliderFlags_None;
    };
        
    //-----------------------------------------------------------------------------
    // mvSliderInt4
    //-----------------------------------------------------------------------------
    MV_REGISTER_WIDGET(mvSliderInt4, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Int4, 1);
    class mvSliderInt4 : public mvInt4PtrBase
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPITEM_TYPE(mvAppItemType::mvSliderInt4, add_slider_int4)

        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_Text              ,  0L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_Bg                ,  7L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_BgHovered         ,  8L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_BgActive          ,  9L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_Grab              , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_GrabActive        , 20L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_Border            ,  5L, 0L);
        MV_CREATE_CONSTANT(mvThemeCol_SliderInt4_BorderShadow      ,  6L, 0L);

        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_Rounding        , 11L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_BorderSize      , 12L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_PaddingX        , 10L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_PaddingY        , 10L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_InnerSpacingX   , 14L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_InnerSpacingY   , 14L, 1L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_GrabMinSize     , 19L, 0L);
        MV_CREATE_CONSTANT(mvThemeStyle_SliderInt4_GrabRounding    , 20L, 0L);

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

        MV_START_COLOR_CONSTANTS
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_Text,         mvColor(255, 255, 255, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_Bg,           mvColor( 41,  74, 122, 138), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_BgHovered,    mvColor( 66, 150, 250, 102), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_BgActive,     mvColor( 66, 150, 250, 171), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_Grab,         mvColor( 61, 133, 224, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_GrabActive,   mvColor( 66, 150, 250, 255), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_Border,       mvColor(110, 110, 128, 128), mvColor(128, 128, 128, 63)),
            MV_ADD_CONSTANT(mvThemeCol_SliderInt4_BorderShadow, mvColor(  0,   0,   0,   0), mvColor(128, 128, 128, 63)),
        MV_END_COLOR_CONSTANTS

        MV_START_STYLE_CONSTANTS
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_Rounding       , 0, 12),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_BorderSize     , 0,  1),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_PaddingX       , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_PaddingY       , 3, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_InnerSpacingX  , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_InnerSpacingY  , 4, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_GrabMinSize    ,10, 20),
            MV_ADD_CONSTANT(mvThemeStyle_SliderInt4_GrabRounding   , 0, 12),
        MV_END_STYLE_CONSTANTS

    public:

        mvSliderInt4(const std::string& name, int* default_value, const std::string& dataSource);
        
        void setEnabled(bool value) override;
        void draw(ImDrawList* drawlist, float x, float y) override;

        void setExtraConfigDict(PyObject* dict) override;
        void getExtraConfigDict(PyObject* dict) override;
        
    private:

        int                 m_min = 0;
        int                 m_max = 100;
        std::string         m_format = "%d";
        ImGuiInputTextFlags m_flags = ImGuiSliderFlags_None;
        ImGuiInputTextFlags m_stor_flags = ImGuiSliderFlags_None;
    };

}
