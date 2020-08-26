#ifndef __WIDGET_TREEVIEW_H__
#define __WIDGET_TREEVIEW_H__

#include <vector>
#include "widget.h"

typedef struct
{
    bool selected;
    std::string name;
    std::string status;
} DATA_DISCOVERY_TASK_ITEM;

typedef struct
{
    bool selected;
    std::string file_name;
    std::string file_path;
    std::string task_name;
    std::string dlp_name;
    std::string result;
} DATA_DISCOVERY_TASK_RESULT_ITEM;

class GTreeViewDD : public GWidget
{
public:
    GTreeViewDD();
    ~GTreeViewDD();

    GtkWidget* create(const char* column_name_name , const char* column_name_status);
    void clear();
    void appendData(bool selected, const char* name, const char* status);
    std::vector<DATA_DISCOVERY_TASK_ITEM> getAllTask();
    std::vector<DATA_DISCOVERY_TASK_ITEM> getAllTaskSelected();
    std::vector<DATA_DISCOVERY_TASK_ITEM> getAllTaskUnSelected();
    static void OnRowActivated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer arg);
};

class GTreeViewDDResult : public GWidget
{
public:
    GTreeViewDDResult();
    ~GTreeViewDDResult();

    GtkWidget* create(const char* column_name_file_name,
                      const char* column_name_file_path,
                      const char* column_name_task_name,
                      const char* column_name_dlp_name,
                      const char* column_name_result);
    void clear();
    void appendData(bool selected, const char* file_name, const char* file_path,
                    const char* task_name, const char* dlp_name, const char* result);
    std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> getAllTask();
    std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> getAllTaskSelected();
    std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> getAllTaskUnSelected();
    static void OnRowActivated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer arg);
};

#endif /* __WIDGET_TREEVIEW_H__ */

