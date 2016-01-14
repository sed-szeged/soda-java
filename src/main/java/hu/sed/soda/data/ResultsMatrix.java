package hu.sed.soda.data;

/**
 * The ResultsMatrix class stores a number of test results.
 */
public class ResultsMatrix {

    private long nativeHandle;

    public enum TestResultType {
        NotExecuted(0), Failed(2), Passed(3);

        private int value;

        private TestResultType(int value) {
            this.value = value;
        }
    };

    /**
     * Creates a new ResultsMatrix instance.
     * <b>Memory cleanup must be called manually!</b>
     * 
     * @see #dispose()
     */
    public ResultsMatrix() {
        initialize();
    }

    /**
     * Adds a new test case to the matrix.
     * <b>Does not increase the coverage bit matrix! You must resize it manually.</b>
     * @see #refitMatrixSize()
     * 
     * @param testCaseName The name of the test case.
     */
    public native void addTestcaseName(String testCaseName);

    /**
     * Adds a new revision number to the matrix.
     * <b>Does not increase the coverage bit matrix! You must resize it manually.</b>
     * @see #refitMatrixSize()
     * 
     * @param revisionNumber The name of the code element.
     */
    public native void addRevisionNumber(int revisionNumber);

    /**
     * Resizes the underlying bit matrix.
     * <b>Must be called after test case and revision addition and before setting results!</b>
     */
    public native void refitMatrixSize();

    /**
     * Sets the result of a specified test.
     * 
     * @param revisionNumber The revision number.
     * @param testCaseName The name of the test case.
     * @param result The result of the test case.
     */
    public void setResult(int revisionNumber, String testCaseName, TestResultType result) {
        setResult(revisionNumber, testCaseName, result.value);
    }

    /**
     * Sets the result of a specified test.
     * 
     * @param revisionNumber The revision number.
     * @param testCaseName The name of the test case.
     * @param result The result of the test case.
     */
    private native void setResult(int revisionNumber, String testCaseName, int result);

    /**
     * Saves the matrix to the specified location.
     * 
     * @param fileName The path where the matrix will be saved to.
     */
    public native void save(String fileName);

    /**
     * Cleans up the memory on the native side.
     * <b>Must be called manually!</b>
     */
    public native void dispose();

    /**
     * Initializes the Results matrix on the native side.
     */
    private native void initialize();

}
