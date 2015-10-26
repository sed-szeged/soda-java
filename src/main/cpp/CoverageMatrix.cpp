#include "hu_sed_soda_data_CoverageMatrix.h"
#include <data/CCoverageMatrix.h>
#include "handle.h"
#include <string>

using namespace soda;

void Java_hu_sed_soda_data_CoverageMatrix_addTestcaseName(JNIEnv *env, jobject obj, jstring testCaseName)
{
    CCoverageMatrix *matrix = getHandle<CCoverageMatrix>(env, obj);
    const char *nameStr = env->GetStringUTFChars(testCaseName, 0);
    std::string name = String(nameStr);
    matrix->addTestcaseName(nameStr);
}

void Java_hu_sed_soda_data_CoverageMatrix_addCodeElementName(JNIEnv *env, jobject obj, jstring codeElementName)
{
    CCoverageMatrix *matrix = getHandle<CCoverageMatrix>(env, obj);
    const char *nameStr = env->GetStringUTFChars(codeElementName, 0);
    std::string name = String(nameStr);
    matrix->addCodeElementName(nameStr);
}

void Java_hu_sed_soda_data_CoverageMatrix_refitMatrixSize(JNIEnv *env, jobject obj)
{
    CCoverageMatrix *matrix = getHandle<CCoverageMatrix>(env, obj);
    matrix->refitMatrixSize();
}

void Java_hu_sed_soda_data_CoverageMatrix_setRelation(JNIEnv *env, jobject obj, jstring testCaseName, jstring codeElementName, jboolean isCovered)
{
    CCoverageMatrix *matrix = getHandle<CCoverageMatrix>(env, obj);
    const char *testNameStr = env->GetStringUTFChars(testCaseName, 0);
    std::string testName = String(testNameStr);
    const char *ceNameStr = env->GetStringUTFChars(codeElementName, 0);
    std::string ceName = String(ceNameStr);
    matrix->setRelation(testName, ceName, isCovered);
}

void Java_hu_sed_soda_data_CoverageMatrix_save(JNIEnv *env, jobject obj, jstring fileName)
{
    CCoverageMatrix *matrix = getHandle<CCoverageMatrix>(env, obj);
    const char *nameStr = env->GetStringUTFChars(fileName, 0);
    matrix->save(nameStr);
}

void Java_hu_sed_soda_data_CoverageMatrix_initialise(JNIEnv *env, jobject obj)
{
    CCoverageMatrix *matrix = new CCoverageMatrix();
    setHandle(env, obj, matrix);
}