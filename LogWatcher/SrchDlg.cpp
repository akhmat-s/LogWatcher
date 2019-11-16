#include "SrchDlg.h"

namespace LogWatcher 
{
SrchDlg::SrchDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	/* ComboBox Color */
	ui.comboBox_1->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_1->setItemData(ui.comboBox_1->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_2->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_2->setItemData(ui.comboBox_2->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_3->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_3->setItemData(ui.comboBox_3->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_4->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_4->setItemData(ui.comboBox_4->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_5->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_5->setItemData(ui.comboBox_5->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_6->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_6->setItemData(ui.comboBox_6->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_7->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_7->setItemData(ui.comboBox_7->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_8->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_8->setItemData(ui.comboBox_8->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_9->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_9->setItemData(ui.comboBox_9->currentIndex(), Qt::BackgroundRole);

	ui.comboBox_10->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(7, QColor(221, 160, 221), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBox_10->setItemData(ui.comboBox_10->currentIndex(), Qt::BackgroundRole);

	m_numberOfAllCollors.append(QBrush(Qt::white));
	m_numberOfAllCollors.append(QBrush(Qt::red));
	m_numberOfAllCollors.append(QBrush(Qt::yellow));
	m_numberOfAllCollors.append(QBrush(Qt::cyan));
	m_numberOfAllCollors.append(QBrush(QColor(238, 130, 238)));
	m_numberOfAllCollors.append(QBrush(QColor(128, 0, 128)));
	m_numberOfAllCollors.append(QBrush(Qt::magenta));
	m_numberOfAllCollors.append(QBrush(QColor(216, 191, 216)));
	m_numberOfAllCollors.append(QBrush(Qt::gray));
	m_numberOfAllCollors.append(QBrush(Qt::green));
	m_numberOfAllCollors.append(QBrush(QColor(30, 144, 255)));

	//-------------------------------------------------------------------

	connect(ui.pushButtonSearch, SIGNAL(clicked()), this, SLOT(accept(), getSearchString(), getComboBoxColor()));

}

SrchDlg::~SrchDlg()
{
}

QStringList SrchDlg::searchString()
{
	/* Regular for Search Window */
	QString srchLine1;
	if( !ui.lineEditAnd_1->text().isEmpty() ) 
    {
		srchLine1 = QString("(?=.*" + ui.lineEditAnd_1->text()) + ")";
		if( !ui.lineEditAnd_2->text().isEmpty() ) 
        {
			srchLine1 += QString("(?=.*" + ui.lineEditAnd_2->text()) + ")";
		}
		if( !ui.lineEditAnd_3->text().isEmpty() ) 
        {
			srchLine1 += QString("(?=.*" + ui.lineEditAnd_3->text()) + ")";
		}
		if( !ui.lineEditAnd_4->text().isEmpty() ) 
        {
			srchLine1 += QString("(?=.*" + ui.lineEditAnd_4->text()) + ")";
		}
		if( !ui.lineEditAnd_5->text().isEmpty() ) 
        {
			srchLine1 += QString("(?=.*" + ui.lineEditAnd_5->text() + ")");
		}
	}

	QString srchLine2;
	if( !ui.lineEditAnd_6->text().isEmpty() ) 
    {
		srchLine2 = QString("(?=.*" + ui.lineEditAnd_6->text() + ")");
		if( !ui.lineEditAnd_7->text().isEmpty() ) 
        {
			srchLine2 += QString("(?=.*" + ui.lineEditAnd_7->text() + ")");
		}
		if( !ui.lineEditAnd_8->text().isEmpty() ) 
        {
			srchLine2 += QString("(?=.*" + ui.lineEditAnd_8->text() + ")");
		}
		if( !ui.lineEditAnd_9->text().isEmpty() ) 
        {
			srchLine2 += QString("(?=.*" + ui.lineEditAnd_9->text() + ")");
		}
		if( !ui.lineEditAnd_10->text().isEmpty() ) 
        {
			srchLine2 += QString("(?=.*" + ui.lineEditAnd_10->text() + ")");
		}
	}

	QString srchLine3;
	if( !ui.lineEditAnd_11->text().isEmpty() ) 
    {
		srchLine3 = QString("(?=.*" + ui.lineEditAnd_11->text() + ")");
		if( !ui.lineEditAnd_12->text().isEmpty() ) 
        {
			srchLine3 += QString("(?=.*" + ui.lineEditAnd_12->text() + ")");
		}
		if( !ui.lineEditAnd_13->text().isEmpty() ) 
        {
			srchLine3 += QString("(?=.*" + ui.lineEditAnd_13->text() + ")");
		}
		if( !ui.lineEditAnd_14->text().isEmpty() ) 
        {
			srchLine3 += QString("(?=.*" + ui.lineEditAnd_14->text() + ")");
		}
		if( !ui.lineEditAnd_15->text().isEmpty() ) 
        {
			srchLine3 += QString("(?=.*" + ui.lineEditAnd_15->text() + ")");
		}
	}

	QString srchLine4;
	if( !ui.lineEditAnd_16->text().isEmpty() ) 
    {
		srchLine4 = QString("(?=.*" + ui.lineEditAnd_16->text() + ")");
		if( !ui.lineEditAnd_17->text().isEmpty() ) 
        {
			srchLine4 += QString("(?=.*" + ui.lineEditAnd_17->text() + ")");
		}
		if( !ui.lineEditAnd_18->text().isEmpty() ) 
        {
			srchLine4 += QString("(?=.*" + ui.lineEditAnd_18->text() + ")");
		}
		if( !ui.lineEditAnd_19->text().isEmpty() ) 
        {
			srchLine4 += QString("(?=.*" + ui.lineEditAnd_19->text() + ")");
		}
		if( !ui.lineEditAnd_20->text().isEmpty() ) 
        {
			srchLine4 += QString("(?=.*" + ui.lineEditAnd_20->text() + ")");
		}
	}

	QString srchLine5;
	if( !ui.lineEditAnd_21->text().isEmpty() ) 
    {
		srchLine5 = QString("(?=.*" + ui.lineEditAnd_21->text() + ")");
		if( !ui.lineEditAnd_22->text().isEmpty() ) 
        {
			srchLine5 += QString("(?=.*" + ui.lineEditAnd_22->text() + ")");
		}
		if( !ui.lineEditAnd_23->text().isEmpty() ) 
        {
			srchLine5 += QString("(?=.*" + ui.lineEditAnd_23->text() + ")");
		}
		if( !ui.lineEditAnd_24->text().isEmpty() ) 
        {
			srchLine5 += QString("(?=.*" + ui.lineEditAnd_24->text() + ")");
		}
		if( !ui.lineEditAnd_25->text().isEmpty() ) 
        {
			srchLine5 += QString("(?=.*" + ui.lineEditAnd_25->text() + ")");
		}
	}

	QString srchLine6;
	if( !ui.lineEditAnd_26->text().isEmpty() ) 
    {
		srchLine6 = QString("(?=.*" + ui.lineEditAnd_26->text() + ")");
		if( !ui.lineEditAnd_27->text().isEmpty() ) 
        {
			srchLine6 += QString("(?=.*" + ui.lineEditAnd_27->text() + ")");
		}
		if( !ui.lineEditAnd_28->text().isEmpty() ) 
        {
			srchLine6 += QString("(?=.*" + ui.lineEditAnd_28->text() + ")");
		}
		if( !ui.lineEditAnd_29->text().isEmpty() ) 
        {
			srchLine6 += QString("(?=.*" + ui.lineEditAnd_29->text() + ")");
		}
		if( !ui.lineEditAnd_30->text().isEmpty() ) 
        {
			srchLine6 += QString("(?=.*" + ui.lineEditAnd_30->text() + ")");
		}
	}

	QString srchLine7;
	if( !ui.lineEditAnd_31->text().isEmpty() ) 
    {
		srchLine7 += QString(".*" + ui.lineEditAnd_31->text() + ")");
		if( !ui.lineEditAnd_32->text().isEmpty() ) 
        {
			srchLine7 += QString(".*" + ui.lineEditAnd_32->text() + ")");
		}
		if( !ui.lineEditAnd_33->text().isEmpty() ) 
        {
			srchLine7 += QString("(?=.*" + ui.lineEditAnd_33->text() + ")");
		}
		if( !ui.lineEditAnd_34->text().isEmpty() ) 
        {
			srchLine7 += QString("(?=.*" + ui.lineEditAnd_34->text() + ")");
		}
		if( !ui.lineEditAnd_35->text().isEmpty() ) 
        {
			srchLine7 += QString("(?=.*" + ui.lineEditAnd_35->text() + ")");
		}
	}

	QString srchLine8;
	if( !ui.lineEditAnd_36->text().isEmpty() ) 
    {
		srchLine8 += QString("(?=.*" + ui.lineEditAnd_36->text() + ")");
		if( !ui.lineEditAnd_37->text().isEmpty() ) 
        {
			srchLine8 += QString("(?=.*" + ui.lineEditAnd_37->text() + ")");
		}
		if( !ui.lineEditAnd_38->text().isEmpty() ) 
        {
			srchLine8 += QString("(?=.*" + ui.lineEditAnd_38->text() + ")");
		}
		if( !ui.lineEditAnd_39->text().isEmpty() ) {
			srchLine8 += QString("(?=.*" + ui.lineEditAnd_39->text() + ")");
		}
		if( !ui.lineEditAnd_40->text().isEmpty() ) {
			srchLine8 += QString("(?=.*" + ui.lineEditAnd_40->text() + ")");
		}
	}

	QString srchLine9;
	if( !ui.lineEditAnd_41->text().isEmpty() ) 
    {
		srchLine9 += QString("(?=.*" + ui.lineEditAnd_41->text() + ")");
		if( !ui.lineEditAnd_42->text().isEmpty() ) 
        {
			srchLine9 += QString("(?=.*" + ui.lineEditAnd_42->text() + ")");
		}
		if( !ui.lineEditAnd_43->text().isEmpty() ) 
        {
			srchLine9 += QString("(?=.*" + ui.lineEditAnd_43->text() + ")");
		}
		if( !ui.lineEditAnd_44->text().isEmpty() ) 
        {
			srchLine9 += QString("(?=.*" + ui.lineEditAnd_44->text() + ")");
		}
		if( !ui.lineEditAnd_45->text().isEmpty() ) 
        {
			srchLine9 += QString("(?=.*" + ui.lineEditAnd_45->text() + ")");
		}
	}

	QString srchLine10;
	if( !ui.lineEditAnd_46->text().isEmpty() ) 
    {
		srchLine10 += QString("(?=.*" + ui.lineEditAnd_46->text() + ")");
		if( !ui.lineEditAnd_47->text().isEmpty() ) 
        {
			srchLine10 += QString("(?=.*" + ui.lineEditAnd_47->text() + ")");
		}
		if( !ui.lineEditAnd_48->text().isEmpty() ) 
        {
			srchLine10 += QString("(?=.*" + ui.lineEditAnd_48->text() + ")");
		}
		if( !ui.lineEditAnd_49->text().isEmpty() ) 
        {
			srchLine10 += QString("(?=.*" + ui.lineEditAnd_49->text() + ")");
		}
		if( !ui.lineEditAnd_50->text().isEmpty() ) 
        {
			srchLine10 += QString("(?=.*" + ui.lineEditAnd_50->text() + ")");
		}
	}


	QStringList srchAll;
	if( !srchLine1.isEmpty() ) 
    {
		srchAll.append(QString(srchLine1));
		if( !srchLine2.isEmpty() ) 
        {
			srchAll.append(QString(srchLine2));
		}
		if( !srchLine3.isEmpty() ) 
        {
			srchAll.append(QString(srchLine3));
		}
		if( !srchLine4.isEmpty() ) 
        {
			srchAll.append(QString(srchLine4));
		}
		if( !srchLine5.isEmpty() ) 
        {
			srchAll.append(QString(srchLine5));
		}
		if( !srchLine6.isEmpty() ) 
        {
			srchAll.append(QString(srchLine6));
		}
		if( !srchLine7.isEmpty() ) 
        {
			srchAll.append(QString(srchLine7));
		}
		if( !srchLine8.isEmpty() ) 
        {
			srchAll.append(QString(srchLine8));
		}
		if( !srchLine9.isEmpty() ) 
        {
			srchAll.append(QString(srchLine9));
		}
		if( !srchLine10.isEmpty() ) 
        {
			srchAll.append(QString(srchLine10));
		}
	}
	return srchAll;
}

QList<QVariant> SrchDlg::findComboBoxColor()
{
	/* Color from Combobox */
	QList<QVariant>  colorAll;
	if( !ui.lineEditAnd_1->text().isEmpty() )
	{
		int c1 = ui.comboBox_1->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c1));
	}
	if( !ui.lineEditAnd_6->text().isEmpty() )
	{
		int c2 = ui.comboBox_2->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c2));
	}
	if( !ui.lineEditAnd_11->text().isEmpty() )
	{
		int c3 = ui.comboBox_3->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c3));
	}
	if( !ui.lineEditAnd_16->text().isEmpty() )
	{
		int c4 = ui.comboBox_4->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c4));
	}
	if( !ui.lineEditAnd_21->text().isEmpty() )
	{
		int c5 = ui.comboBox_5->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c5));
	}
	if( !ui.lineEditAnd_26->text().isEmpty() )
	{
		int c6 = ui.comboBox_6->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c6));
	}
	if( !ui.lineEditAnd_31->text().isEmpty() )
	{
		int c7 = ui.comboBox_7->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c7));
	}
	if (!ui.lineEditAnd_36->text().isEmpty())
	{
		int c8 = ui.comboBox_8->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c8));
	}
	if( !ui.lineEditAnd_41->text().isEmpty() )
	{
		int c9 = ui.comboBox_9->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c9));
	}
	if( !ui.lineEditAnd_46->text().isEmpty() )
	{
		int c10 = ui.comboBox_10->currentIndex();
		colorAll.append(m_numberOfAllCollors.at(c10));
	}
	return colorAll;
}
}