#include "mvInterfaceRegistry.h"
#include "mvInterfaces.h"
#include "mvPythonModule.h"
#include <functional>
#include "Core/mvApp.h"

namespace Marvel {

	mvInterfaceRegistry* mvInterfaceRegistry::s_instance = nullptr;

	std::map<std::string, mvPythonTranslator>& mvInterfaceRegistry::getPythonInterface(const std::string& name)
	{ 
		return m_translators[name]; 
	}

	std::vector<std::pair<std::string, long>>& mvInterfaceRegistry::getConstants()
	{ 
		return m_constants; 
	}

	mvInterfaceRegistry* mvInterfaceRegistry::GetRegistry()
	{
		if (s_instance)
			return s_instance;

		s_instance = new mvInterfaceRegistry();

		//auto initializer = mvApp::GetApp()->getModuleInitializer();
		auto initializer = mvModuleInitializer::getInitializer();
		int startindex = initializer->initializeCoreModules();
		initializer->initializeUserModules(startindex);
		//initModules();
		return s_instance;
	}

	mvInterfaceRegistry::mvInterfaceRegistry()
	{
		m_constants = BuildConstantsInterface();
	}

	void mvInterfaceRegistry::addModule(const char* name, pyInitFunc initfunc, pyDocFunc docfunc)
	{
		if(docfunc)
			m_translators[name] = docfunc();
		m_modules.push_back(initfunc);
	}

	pyInitFunc mvInterfaceRegistry::getInitFunc(int i)
	{
		return m_modules[i];
	}

	std::vector<const char*> mvInterfaceRegistry::getPythonInterfaceCommands(const std::string& name)
	{
		std::map<std::string, mvPythonTranslator>& docmap = m_translators[name];

		std::vector<const char*> commandvec;

		for (const auto& item : docmap)
			commandvec.emplace_back(item.first.c_str());

		return commandvec;
	}

	std::vector<const char*> mvInterfaceRegistry::getPythonInterfaceDoc(const std::string& name)
	{
		std::map<std::string, mvPythonTranslator>& docmap = m_translators[name];

		std::vector<const char*> docvec;

		for (const auto& item : docmap)
			docvec.emplace_back(item.second.getDocumentation());

		return docvec;
	}

	std::vector<const char*> mvInterfaceRegistry::getConstantsCommands()
	{
		std::vector<const char*> commandvec;

		for (const auto& item : m_constants)
			commandvec.emplace_back(item.first.c_str());

		return commandvec;
	}

	std::vector<long> mvInterfaceRegistry::getConstantsValue()
	{
		std::vector<long> commandvec;

		for (const auto& item : m_constants)
			commandvec.push_back(item.second);

		return commandvec;
	}

}