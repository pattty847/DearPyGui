#include "mvMenuItem.h"
#include "mvApp.h"
#include "mvItemRegistry.h"

namespace Marvel {

	void mvMenuItem::InsertParser(std::map<std::string, mvPythonParser>* parsers)
	{

		mvPythonParser parser(mvPyDataType::UUID, "Undocumented function", { "Widgets" });
		mvAppItem::AddCommonArgs(parser, (CommonParserArgs)(
			MV_PARSER_ARG_ID |
			MV_PARSER_ARG_INDENT |
			MV_PARSER_ARG_PARENT |
			MV_PARSER_ARG_BEFORE |
			MV_PARSER_ARG_LABEL |
			MV_PARSER_ARG_CALLBACK |
			MV_PARSER_ARG_USER_DATA |
			MV_PARSER_ARG_SHOW |
			MV_PARSER_ARG_FILTER |
			MV_PARSER_ARG_DROP_CALLBACK |
			MV_PARSER_ARG_DRAG_CALLBACK |
			MV_PARSER_ARG_PAYLOAD_TYPE |
			MV_PARSER_ARG_TRACKED |
			MV_PARSER_ARG_ENABLED)
		);

		parser.addArg<mvPyDataType::Bool>("default_value", mvArgType::KEYWORD_ARG, "False");

		parser.addArg<mvPyDataType::String>("shortcut", mvArgType::KEYWORD_ARG, "''", "Adds a shortcut.");

		parser.addArg<mvPyDataType::Bool>("check", mvArgType::KEYWORD_ARG, "False", "Makes menu item with checkmark.");

		parser.finalize();

		parsers->insert({ s_command, parser });
	}

	mvMenuItem::mvMenuItem(mvUUID uuid)
		: mvBoolPtrBase(uuid) 
	{
	}

	void mvMenuItem::draw(ImDrawList* drawlist, float x, float y)
	{
		ScopedID id(m_uuid);

		// This is ugly and goes against our style system but its the only widget that ImGui chooses to push teh disable color for us
		// so we have to map our text disable color to the system text disable color, or we can create a new constant which goes agains our 
		// constants. 
		ImGui::PushStyleColor(ImGuiCol_TextDisabled, ImGui::GetStyleColorVec4(ImGuiCol_Text));

		// create menu item and see if its selected
		if (ImGui::MenuItem(m_label.c_str(), m_shortcut.c_str(), m_check ? m_value.get() : nullptr, m_enabled))
		{
			mvApp::GetApp()->getCallbackRegistry().addCallback(m_callback, m_uuid, nullptr, m_user_data);
		}

		ImGui::PopStyleColor();

	}

	void mvMenuItem::handleSpecificKeywordArgs(PyObject* dict)
	{
		if (dict == nullptr)
			return;

		if (PyObject* item = PyDict_GetItemString(dict, "shortcut")) m_shortcut = ToString(item);
		if (PyObject* item = PyDict_GetItemString(dict, "check")) m_check = ToBool(item);

}

	void mvMenuItem::getSpecificConfiguration(PyObject* dict)
	{
		if (dict == nullptr)
			return;

		PyDict_SetItemString(dict, "shortcut", ToPyString(m_shortcut));
		PyDict_SetItemString(dict, "check", ToPyBool(m_check));
	}

}
