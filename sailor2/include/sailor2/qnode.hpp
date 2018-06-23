/**
 * @file /include/sailor2/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef sailor2_QNODE_HPP_
#define sailor2_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include "dataLib.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sailor2 {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread
{
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
//	bool init();
//	bool init(const std::string &master_url, const std::string &host_url);
//	void run();

	/*********************
	** Logging
	**********************/


Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
        ros::Subscriber image_sub;
        ros::Subscriber boundingbox_sub;
    QStringListModel logging_model;
};

}  // namespace sailor2

#endif /* sailor2_QNODE_HPP_ */
