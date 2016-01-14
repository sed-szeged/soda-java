#include "hu_sed_soda_data_ResultsMatrix.h"
#include "handle.h"
#include <data/CResultsMatrix.h>
#include <string>

using namespace soda;

void Java_hu_sed_soda_data_ResultsMatrix_addTestcaseName(JNIEnv *env, jobject obj, jstring testCaseName)
{
    CResultsMatrix *matrix = getHandle<CResultsMatrix>(env, obj);
    const char *nameStr = env->GetStringUTFChars(testCaseName, 0);
    std::string name = std::string(nameStr);
    matrix->addTestcaseName(name);
}

void Java_hu_sed_soda_data_ResultsMatrix_addRevisionNumber(JNIEnv *env, jobject obj, jint revision)
{
    CResultsMatrix *matrix = getHandle<CResultsMatrix>(env, obj);
    matrix->addRevisionNumber(revision);
}

void Java_hu_sed_soda_data_ResultsMatrix_refitMatrixSize(JNIEnv *env, jobject obj)
{
    CResultsMatrix *matrix = getHandle<CResultsMatrix>(env, obj);
    matrix->refitMatrixSize();
}

void Java_hu_sed_soda_data_ResultsMatrix_setResult(JNIEnv *env, jobject obj, jint revision, jstring testCaseName, jint result)
{
    CResultsMatrix *matrix = getHandle<CResultsMatrix>(env, obj);
    const char *nameStr = env->GetStringUTFChars(testCaseName, 0);
    std::string testName = std::string(nameStr);
    CResultsMatrix::TestResultType testResult = static_cast<CResultsMatrix::TestResultType>(result);
    matrix->setResult(revision, testName, testResult);
}

void Java_hu_sed_soda_data_ResultsMatrix_save(JNIEnv *env, jobject obj, jstring fileName)
{
    CResultsMatrix *matrix = getHandle<CResultsMatrix>(env, obj);
    const char *nameStr = env->GetStringUTFChars(fileName, 0);
    matrix->save(nameStr);
}

void Java_hu_sed_soda_data_ResultsMatrix_dispose(JNIEnv *env, jobject obj)
{
    CResultsMatrix *matrix = getHandle<CResultsMatrix>(env, obj);
    setHandle<CResultsMatrix>(env, obj, NULL);
    delete matrix;
}

void Java_hu_sed_soda_data_ResultsMatrix_initialize(JNIEnv *env, jobject obj)
{
    CResultsMatrix *matrix = new CResultsMatrix();
    setHandle<CResultsMatrix>(env, obj, matrix);
}
