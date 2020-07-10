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

	jvm->DestroyJavaVM();

	return 1;
}