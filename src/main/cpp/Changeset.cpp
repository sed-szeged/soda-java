#include "hu_sed_soda_data_Changeset.h"
#include "handle.h"
#include <data/CChangeset.h>
#include <string>

using namespace soda;

void Java_hu_sed_soda_data_Changeset_addCodeElement(JNIEnv *env, jobject obj, jstring codeElementName)
{
    CChangeset *matrix = getHandle<CChangeset>(env, obj);
    const char *nameStr = env->GetStringUTFChars(codeElementName, 0);
    std::string ceName = std::string(nameStr);
    matrix->addCodeElementName(ceName);
}

void Java_hu_sed_soda_data_Changeset_addRevision(JNIEnv *env, jobject obj, jint revisionNumber)
{
    CChangeset *matrix = getHandle<CChangeset>(env, obj);
    matrix->addRevision(revisionNumber);
}

void Java_hu_sed_soda_data_Changeset_refitMatrixSize(JNIEnv *env, jobject obj)
{
    CChangeset *matrix = getHandle<CChangeset>(env, obj);
    matrix->refitSize();
}

void Java_hu_sed_soda_data_Changeset_setChange(JNIEnv *env, jobject obj, jint revisionNumber, jstring codeElementName, jboolean isChanged)
{
    CChangeset *matrix = getHandle<CChangeset>(env, obj);
    const char *nameStr = env->GetStringUTFChars(codeElementName, 0);
    std::string ceName = std::string(nameStr);
    matrix->setChange(revisionNumber, ceName, isChanged);
}

void Java_hu_sed_soda_data_Changeset_save(JNIEnv *env, jobject obj, jstring fileName)
{
    CChangeset *matrix = getHandle<CChangeset>(env, obj);
    const char *nameStr = env->GetStringUTFChars(fileName, 0);
    matrix->save(nameStr);
}

void Java_hu_sed_soda_data_Changeset_dispose(JNIEnv *env, jobject obj)
{
    CChangeset *matrix = getHandle<CChangeset>(env, obj);
    setHandle<CChangeset>(env, obj, NULL);
    delete matrix;
}

void Java_hu_sed_soda_data_Changeset_initialize(JNIEnv *env, jobject obj)
{
    CChangeset *matrix = new CChangeset();
    setHandle<CChangeset>(env, obj, matrix);
}
