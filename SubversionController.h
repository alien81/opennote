#ifndef SYNC_H_
#define SYNC_H_

#include <QMainWindow>
#include <QMap>
#include <QListWidget>
#include <QTreeWidget>
#include <QPointer>
#include <QTreeView>
#include <QDirModel>
#include <QProcess>

const QString repository_url = "file:///c:/teamnote_svn/teamnote/trunk";

class SubversionController {
public:
	SubversionController(QString workingDir);
	virtual ~SubversionController();

	QByteArray doUpdate();
	void doAdd(QString fileName);
	void doCommit(QString fileName);
	void doMove(QString srcFileName, QString dstFileName);
	QString getDateInfo(QString fileName);

	QString shm;
private:
	QString workingDirectory;
	QProcess *svnProcess;
};

// --> svn co file:///c:/teamnote_svn/teamnote/trunk teamnote
// --> svn ci

// ��Ʈ�� �߰�, ���� �߰� (by �����) ====> �ٷ� �߰� (�ȵǸ� pending command list �� �־�α�)
// Status â ===> ���� �ֽŻ����� �������� �ƴ��� ǥ�õǾ�� �Ѵ�.
// ������(ó������, +3��, ..) ===> svn update �ؼ� �̹ݿ��� ���ϵ� �� ����Ʈ�� �߰��ϰ�
//                         ===> svn st -q �ؼ� �ֽ� ������ ���ϰ� diff �Ѱ� �����ֱ�
//						   ===> pending command list �� �ִ� ��� ������!
//                         !!!! ������� ������Ʈ �ϴ� ���߿��� Mutex ������ ��ȣ�ϱ�

#endif /* SYNC_H_ */
