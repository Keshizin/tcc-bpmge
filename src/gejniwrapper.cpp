/*
	Game Engine JNI Wrapper

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

// #include <gejniwrapper.h>
// #include <iostream>

// GEJNIWrapper::GEJNIWrapper()
// {
// 	jvm = 0;
// 	jni_env = 0;
// }

// int GEJNIWrapper::startJVM()
// {
// 	JavaVMInitArgs vm_args;
// 	JavaVMOption jvmopt[1];

// 	// "-Djava.class.path=src;lib\\camunda-bpmn-model-7.13.0-alpha3.jar;lib\\camunda-xml-model-7.13.0-alpha3.jar;";
// 	// "-Djava.class.path=src\\java;";
// 	jvmopt[0].optionString = (char*)java_class_path.c_str();

// 	vm_args.version = JNI_VERSION_1_2;
// 	vm_args.nOptions = 1;
// 	vm_args.options = jvmopt;
// 	vm_args.ignoreUnrecognized = JNI_TRUE;

// 	jint rc = JNI_CreateJavaVM(&jvm, (void**)&jni_env, &vm_args);

// 	if(rc != JNI_OK)
// 	{
// 		std::cout << "(!) ERROR It was not possible to create JVM." << std::endl;
// 		return 0;
// 	}

// 	return 1;
// }

// int GEJNIWrapper::destroyJVM()
// {
// 	return !jvm->DestroyJavaVM();
// }

// int GEJNIWrapper::callJavaMethod(std::string className, std::string javaMethod)
// {
// 	jclass javaClass = jni_env->FindClass(className.c_str());

// 	if(javaClass == NULL)
// 	{
// 		std::cout << "(!) Java class not found." << std::endl;
// 		jni_env->ExceptionDescribe();
// 		jvm->DestroyJavaVM();
// 		return 0;
// 	}

// 	jmethodID methodId = jni_env->GetStaticMethodID(javaClass, javaMethod.c_str(), "()V");

// 	if(methodId == NULL)
// 		std::cout << "(!) ERROR Method is not found!" << std::endl;
// 	else
// 	{
// 		jni_env->CallStaticObjectMethod(javaClass, methodId);

// 		if (jni_env->ExceptionCheck()) {
// 			jni_env->ExceptionDescribe();
// 			jni_env->ExceptionClear();
// 		}
// 	}

// 	return 1;
// }

// void GEJNIWrapper::setJavaClassPath(std::string java_class_path)
// {
// 	this->java_class_path = java_class_path;
// }

// std::string GEJNIWrapper::getJavaClassPath()
// {
// 	return java_class_path;
// }