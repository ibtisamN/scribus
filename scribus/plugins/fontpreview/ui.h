#ifndef FONTPREVIEW_H
#define FONTPREVIEW_H

//#include <qvariant.h>
//#include <qdialog.h>

#include "scribus.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QListView;
class QListViewItem;
class QListBoxItem;
class QPushButton;
class QLabel;
class QSpinBox;

class FontPreview : public QDialog
{
	Q_OBJECT

public:
	FontPreview(ScribusApp *carrier, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0);
	~FontPreview();

	/** Reference on the parent application object */
	ScribusApp *carrier;
	/** gui widgets */
	QLabel* searchLabel;
	QLineEdit* searchEdit;
	QPushButton* searchButton;
	QListView* fontList;
	QPushButton* okButton;
	QPushButton* cancelButton;
	QLabel* fontPreview;
	QLabel* sizeLabel;
	QSpinBox* sizeSpin;
	/** Font iteration */
	QMap<QString,QFont> reallyUsedFonts;
	/** Pixmaps for each font type */
	QPixmap ttfFont;
	QPixmap otfFont;
	QPixmap psFont;
	QPixmap okIcon;

public slots:
	virtual void fontList_changed();

protected:
	/** gui layout */
	QGridLayout* FontPreviewLayout;
	QHBoxLayout* searchLayout;
	QVBoxLayout* layout6;
	QHBoxLayout* layout5;
	QVBoxLayout* layout2;
	QVBoxLayout* layout1;
	QHBoxLayout* sizeLayout;
	QVBoxLayout* listLayout;
	/** Configuration structure */
	PrefsContext* prefs;
    /*! Column for sorting. */
    uint sortColumn;
    /*! window size */
    uint xsize;
    uint ysize;
	/*! Setup fontList by search string.
	If the search string is empty list all fonts */
	void updateFontList(QString);

protected slots:
	/** tr() */
	virtual void languageChange();
	/** Called after each text change.
	It checks the string length for 0 length- calling font list re-filling with all
	fonts = without search filter. Of course that search filling can be used afterall
	all changes but it will slow down the dialog. */
	virtual void searchEdit_textChanged(const QString &);
	/** Fill the font list by search mask. */
	virtual void searchButton_clicked();
};

#endif // FONTPREVIEW_H

