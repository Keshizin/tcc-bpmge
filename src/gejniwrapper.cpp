/*
	Game Engine JNI Wrapper
	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
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