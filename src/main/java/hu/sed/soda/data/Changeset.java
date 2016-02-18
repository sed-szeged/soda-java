package hu.sed.soda.data;

/**
 * The Changeset class stores which code elements were changed in multiple
 * revisions.
 */
public class Changeset {

  /**
   * Creates a new Changeset instance.
   * <b>Memory cleanup must be called manually!</b>
   * 
   * @see #dispose()
   */
  public Changeset() {
    initialize();
  }

  /**
   * Adds a new code element to the matrix.
   * <b>Does not increase the matrix! You must resize it manually.</b>
   * @see #refitMatrixSize()
   * 
   * @param codeElementName The name of the code element.
   */
  public native void addCodeElement(String codeElementName);

  /**
   * Adds a specific revision number to the change set.
   * <b>Does not increase the matrix! You must resize it manually.</b>
   * @see #refitMatrixSize()
   * 
   * @param revisionNumber The revision number.
   */
  public native void addRevision(int revisionNumber);

  /**
   * Resizes the underlying matrix.
   * 
   * <b>Must be called after code element and revision addition and before setting changes!</b>
   */
  public native void refitMatrixSize();

  /**
   * Sets the given value to the specified code element in the specified revision.
   * 
   * @param revisionNumber The revision number.
   * @param codeElementName The name of the code element.
   * @param isChanged True if the code element were changed in the given revision, false otherwise.
   */
  public native void setChange(int revisionNumber, String codeElementName, boolean isChanged);

  /**
   * Saves the matrix to the specified location.
   * 
   * @param fileName The path where the matrix will be saved to.
   */
  public native void save(String fileName);

  /**
   * Cleans up the memory on the native side.
   * 
   * <b>Must be called manually!</b>
   */
  public native void dispose();

  /**
   * Initialises the Changeset matrix on the native side.
   */
  private native void initialize();

}
