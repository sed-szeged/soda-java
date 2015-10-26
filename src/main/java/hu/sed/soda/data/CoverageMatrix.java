package hu.sed.soda.data;

public class CoverageMatrix {
    private long nativeHandle;

    public CoverageMatrix() {
        initialise();
    }

    public native void addTestcaseName(String testCaseName);
    public native void addCodeElementName(String codeElementName);
    public native void refitMatrixSize();
    public native void setRelation(String testCaseName, String codeElementName, boolean isCovered);
    public native void save(String fileName);

    public native void dispose();

    private native void initialise();

}
