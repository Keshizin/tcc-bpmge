/*
	Game Engine JNI Wrapper

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#include <gejniwrapper.h>
#include <iostream>

int GEJNIWrapper::startJVM()
{
	JavaVM *jvm;
	JNIEnv *env;
	JavaVMInitArgs vm_args;
	JavaVMOption jvmopt[1];

	// char path[200]="-Djava.class.path=src;lib\\camunda-bpmn-model-7.13.0-alpha3.jar;lib\\camunda-xml-model-7.13.0-alpha3.jar;";
	std::string classpath = "-Djava.class.path=src\\java;";
	jvmopt[0].optionString = (char*)classpath.c_str();

	vm_args.version = JNI_VERSION_1_2;
	vm_args.nOptions = 1;
	vm_args.options = jvmopt;
	vm_args.ignoreUnrecognized = JNI_TRUE;

	jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

	if(rc != JNI_OK)
	{
		std::cout << "(!) ERROR It was not possible to create JVM." << std::endl;
		return 0;
	}

	jclass jclass = env->FindClass("BPMNParser");

	if(jclass == NULL)
	{
		std::cout << "(!) Java class not found." << std::endl;
		env->ExceptionDescribe();
		jvm->DestroyJavaVM();
		return 0;
	}

	jmethodID methodId = env->GetStaticMethodID(jclass, "print", "()V");

	if(methodId == NULL)
		std::cout << "(!) ERROR Method is not found!" << std::endl;
	else
	{
		env->CallStaticObjectMethod(jclass, methodId);

		if (env->ExceptionCheck()) {
			env->ExceptionDescribe();
			env->ExceptionClear();
		}
	}

	jvm->DestroyJavaVM();

	return 1;
}