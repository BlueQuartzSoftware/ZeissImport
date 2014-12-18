/*
 * Your License or Copyright Information can go here
 */

#ifndef _CalculateBackground_H_
#define _CalculateBackground_H_


#include <QtCore/QString>
#include <QtXml/QDomDocument>

#include "DREAM3DLib/DREAM3DLib.h"
#include "DREAM3DLib/Common/DREAM3DSetGetMacros.h"
#include "DREAM3DLib/Common/AbstractFilter.h"

#include "ZeissImport/ZeissXml/ZeissTagsXmlSection.h"

/**
 * @class CalculateBackground CalculateBackground.h ZeissImport/CalculateBackgrounds/CalculateBackground.h
 * @brief
 * @author
 * @date
 * @version 1.0
 */
class CalculateBackground : public AbstractFilter
{
  Q_OBJECT /* Need this for Qt's signals and slots mechanism to work */

  public:
    DREAM3D_SHARED_POINTERS(CalculateBackground)
    DREAM3D_STATIC_NEW_MACRO(CalculateBackground)
    DREAM3D_TYPE_MACRO_SUPER(CalculateBackground, AbstractFilter)

    virtual ~CalculateBackground();

    DREAM3D_FILTER_PARAMETER(QString, VolumeDataContainerName)
    Q_PROPERTY(QString VolumeDataContainerName READ getVolumeDataContainerName WRITE setVolumeDataContainerName)

    DREAM3D_FILTER_PARAMETER(QString, BackgroundAttributeMatrixName)
    Q_PROPERTY(QString BackgroundAttributeMatrixName READ getBackgroundAttributeMatrixName WRITE setBackgroundAttributeMatrixName)

    DREAM3D_FILTER_PARAMETER(QString, CellAttributeMatrixName)
    Q_PROPERTY(QString CellAttributeMatrixName READ getCellAttributeMatrixName WRITE setCellAttributeMatrixName)

    DREAM3D_FILTER_PARAMETER(DataArrayPath, ImageDataArrayPath)
    Q_PROPERTY(DataArrayPath ImageDataArrayPath READ getImageDataArrayPath WRITE setImageDataArrayPath)

    DREAM3D_FILTER_PARAMETER(QString, PolynomialCoefficientsArrayName)
    Q_PROPERTY(QString PolynomialCoefficientsArrayName READ getPolynomialCoefficientsArrayName WRITE setPolynomialCoefficientsArrayName)



    DREAM3D_FILTER_PARAMETER(QString, DataContainerBundleName)
    Q_PROPERTY(QString DataContainerBundleName READ getDataContainerBundleName WRITE setDataContainerBundleName)

    DREAM3D_FILTER_PARAMETER(int, lowThresh)
    Q_PROPERTY(int lowThresh READ getlowThresh WRITE setlowThresh)

    DREAM3D_FILTER_PARAMETER(int, highThresh)
    Q_PROPERTY(int highThresh READ gethighThresh WRITE sethighThresh)




    /**
     * @brief getCompiledLibraryName Returns the name of the Library that this filter is a part of
     * @return
     */
    virtual const QString getCompiledLibraryName();

    /**
    * @brief This returns a string that is displayed in the GUI. It should be readable
    * and understandable by humans.
    */
    virtual const QString getHumanLabel();

    /**
    * @brief This returns the group that the filter belonds to. You can select
    * a different group if you want. The string returned here will be displayed
    * in the GUI for the filter
    */
    virtual const QString getGroupName();

    /**
    * @brief This returns a string that is displayed in the GUI and helps to sort the filters into
    * a subgroup. It should be readable and understandable by humans.
    */
    virtual const QString getSubGroupName();

    /**
    * @brief This method will instantiate all the end user settable options/parameters
    * for this filter
    */
    virtual void setupFilterParameters();

    /**
    * @brief This method will write the options to a file
    * @param writer The writer that is used to write the options to a file
    * @param index The index that the data should be written to
    * @return Returns the next index for writing
    */
    virtual int writeFilterParameters(AbstractFilterParametersWriter* writer, int index);

    /**
    * @brief This method will read the options from a file
    * @param reader The reader that is used to read the options from a file
    * @param index The index to read the information from
    */
    virtual void readFilterParameters(AbstractFilterParametersReader* reader, int index);

   /**
    * @brief Reimplemented from @see AbstractFilter class
    */
    virtual void execute();

    /**
    * @brief This function runs some sanity checks on the DataContainer and inputs
    * in an attempt to ensure the filter can process the inputs.
    */
    virtual void preflight();

    /**
     * @brief newFilterInstance Returns a new instance of the filter optionally copying the filter parameters from the
     * current filter to the new instance.
     * @param copyFilterParameters
     * @return
     */
    virtual AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters);

  signals:
    /**
     * @brief updateFilterParameters This is emitted when the filter requests all the latest Filter Parameters need to be
     * pushed from a user facing control such as the FilterParameter Widget
     * @param filter The filter to push the values into
     */
    void updateFilterParameters(AbstractFilter* filter);

    /**
     * @brief parametersChanged This signal can be emitted when any of the filter parameters are changed internally.
     */
    void parametersChanged();

    /**
     * @brief preflightAboutToExecute Emitted just before the dataCheck() is called. This can change if needed.
     */
    void preflightAboutToExecute();

    /**
     * @brief preflightExecuted Emitted just after the dataCheck() is called. Typically. This can change if needed.
     */
    void preflightExecuted();

  protected:
    CalculateBackground();

    /**
    * @brief Checks for the appropriate parameter values and availability of arrays in the data container
    */
    void dataCheck();

    /**
     * @brief readMetaXml
     * @param device
     * @return
     */


    /**
     * @brief parseRootTagsSection
     * @param tags
     * @return
     */

    /**
     * @brief parseImages
     * @param rootTags
     */
    void generateMetaDataAttributeMatrix(DataContainer *dc, ZeissTagsXmlSection::Pointer photoTagsSection);

  private:
    /* Your private class instance variables go here. You can use several preprocessor macros to help
     * make sure you have all the variables defined correctly. Those are "DEFINE_REQUIRED_DATAARRAY_VARIABLE()"
     * and  DEFINE_CREATED_DATAARRAY_VARIABLE() which are defined in DREAM3DGetSetMacros.h
     */

    int64_t m_totalPoints;
//    uint64_t m_lowThresh;
//    uint64_t m_highThresh;

    DEFINE_CREATED_DATAARRAY_VARIABLE(double, PolynomialCoefficients)

    CalculateBackground(const CalculateBackground&); // Copy Constructor Not Implemented
    void operator=(const CalculateBackground&); // Operator '=' Not Implemented
};

#endif /* _CalculateBackground_H_ */