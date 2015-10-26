package hu.sed.soda.data;

public class CoverageMatrix {
    private long nativeHandle;

    /**
     * Creates a new CoverageMatrix instance.
     * Memory cleanup must be called manually!
     * @see #dispose()
     */
    public CoverageMatrix() {
        initialise();
    }

    /**
     * Adds a new test case to the matrix.
     * Does not increase the coverage bit matrix! You must resize it manually.
     * @see #refitMatrixSize()
     * @param testCaseName The name of the test case.
     */
    public native void addTestcaseName(String testCaseName);

    /**
     * Adds a new code element to the matrix.
     * Does not increase the coverage bit matrix! You must resize it manually.
     * @see #refitMatrixSize()
     * @param codeElementName The name of the code element.
     */
    public native void addCodeElementName(String codeElementName);

    /**
     * Resize the coverage bit matrix.
     * Must be called after test case and code element addition and before setting relation!
     */
    public native void refitMatrixSize();

    /**
     * Sets the coverage relation between a test case and a code element.
     * @param testCaseName The name of the test case.
     * @param codeElementName The name of the code element.
     * @param isCovered Whether the test case covers the code element or not.
     */
    public native void setRelation(String testCaseName, String codeElementName, boolean isCovered);

    /**
     * Saves the matrix to the specified location.
     * @param fileName The path where tha matrix will be saved to.
     */
    public native void save(String fileName);

    /**
     * Cleans up the memory on the native side.
     * Must be called manually!
     */
    public native void dispose();

    /**
     * Initialise the Coverage matrix on the native side.
     */
    private native void initialise();

}
