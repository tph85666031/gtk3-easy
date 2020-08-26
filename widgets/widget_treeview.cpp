#include "widget_treeview.h"

GTreeViewDD::GTreeViewDD()
{
}

GTreeViewDD::~GTreeViewDD()
{
}

GtkWidget* GTreeViewDD::create(const char* column_name_name , const char* column_name_status)
{
    GtkListStore *store = gtk_list_store_new(3, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
    this->widget = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));

    GtkTreeViewColumn* column_toggle = gtk_tree_view_column_new_with_attributes("",
                                       gtk_cell_renderer_toggle_new(), "active", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_toggle);

    GtkTreeViewColumn* column_name = gtk_tree_view_column_new_with_attributes(column_name_name,
                                     gtk_cell_renderer_text_new(), "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_name);

    GtkTreeViewColumn* column_status = gtk_tree_view_column_new_with_attributes(column_name_status,
                                       gtk_cell_renderer_text_new(), "text", 2, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_status);

    gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(this->widget), GTK_TREE_VIEW_GRID_LINES_BOTH);

    g_signal_connect(this->widget, "row-activated", G_CALLBACK(OnRowActivated), NULL);

    return this->widget;
}

void GTreeViewDD::clear()
{
    GtkTreeModel* tree_model =  gtk_tree_view_get_model(GTK_TREE_VIEW(this->widget));
    gtk_list_store_clear(GTK_LIST_STORE(tree_model));
}

void GTreeViewDD::appendData(bool selected, const char* name, const char* status)
{
    GtkTreeIter iter;
    GtkTreeModel* tree_model =  gtk_tree_view_get_model(GTK_TREE_VIEW(this->widget));
    gtk_list_store_append(GTK_LIST_STORE(tree_model), &iter);
    gtk_list_store_set(GTK_LIST_STORE(tree_model), &iter,
                       0, selected ? 1 : 0,
                       1, name,
                       2, status,
                       -1);
}

void GTreeViewDD::OnRowActivated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer arg)
{
    GtkTreeSelection *selection = gtk_tree_view_get_selection(tree_view);
    int value = 0;
    GtkTreeIter iter;
    GtkTreeModel *tree_model;
    gtk_tree_selection_get_selected(selection, &tree_model, &iter);
    gtk_tree_model_get(tree_model, &iter, 0, &value, -1);
    if(value)
    {
        value = 0;
    }
    else
    {
        value = 1;
    }
    gtk_list_store_set(GTK_LIST_STORE(tree_model), &iter, 0, value, -1);
}


std::vector<DATA_DISCOVERY_TASK_ITEM> GTreeViewDD::getAllTask()
{
    std::vector<DATA_DISCOVERY_TASK_ITEM> list;

    GtkTreeIter iter;
    GtkTreeModel* tree_model =  gtk_tree_view_get_model(GTK_TREE_VIEW(this->widget));
    if(tree_model == NULL)
    {
        return list;
    }
    gboolean valid = gtk_tree_model_get_iter_first(tree_model, &iter);
    while(valid)
    {
        gint selected = 0;
        gchar *name = NULL;
        gchar* status = NULL;

        gtk_tree_model_get(tree_model, &iter,
                           0, &selected,
                           1, &name,
                           2, &status,
                           -1);

        DATA_DISCOVERY_TASK_ITEM item;
        item.selected = selected;

        if(name != NULL)
        {
            item.name = name;
            g_free(name);
        }
        if(name != NULL)
        {
            item.status = status;
            g_free(status);
        }

        list.push_back(item);

        valid = gtk_tree_model_iter_next(tree_model, &iter);
    }

    return list;
}

std::vector<DATA_DISCOVERY_TASK_ITEM> GTreeViewDD::getAllTaskSelected()
{
    std::vector<DATA_DISCOVERY_TASK_ITEM> list = getAllTask();
    auto iter = list.begin();
    while(iter != list.end())
    {
        if(iter->selected == false)
        {
            iter = list.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return list;
}

std::vector<DATA_DISCOVERY_TASK_ITEM> GTreeViewDD::getAllTaskUnSelected()
{
    std::vector<DATA_DISCOVERY_TASK_ITEM> list = getAllTask();
    auto iter = list.begin();
    while(iter != list.end())
    {
        if(iter->selected == true)
        {
            iter = list.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return list;
}


GTreeViewDDResult::GTreeViewDDResult()
{
}

GTreeViewDDResult::~GTreeViewDDResult()
{
}

GtkWidget* GTreeViewDDResult::create(const char* column_name_file_name,
                                     const char* column_name_file_path,
                                     const char* column_name_task_name,
                                     const char* column_name_dlp_name,
                                     const char* column_name_result)
{
    GtkListStore *store = gtk_list_store_new(6, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,
                          G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    this->widget = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));

    GtkTreeViewColumn* column_toggle = gtk_tree_view_column_new_with_attributes("",
                                       gtk_cell_renderer_toggle_new(), "active", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_toggle);

    GtkTreeViewColumn* column_file_name = gtk_tree_view_column_new_with_attributes(column_name_file_name,
                                          gtk_cell_renderer_text_new(), "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_file_name);

    GtkTreeViewColumn* column_file_path = gtk_tree_view_column_new_with_attributes(column_name_file_path,
                                          gtk_cell_renderer_text_new(), "text", 2, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_file_path);

    GtkTreeViewColumn* column_task_name = gtk_tree_view_column_new_with_attributes(column_name_task_name,
                                          gtk_cell_renderer_text_new(), "text", 3, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_task_name);

    GtkTreeViewColumn* column_dlp_name = gtk_tree_view_column_new_with_attributes(column_name_dlp_name,
                                         gtk_cell_renderer_text_new(), "text", 4, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_dlp_name);

    GtkTreeViewColumn* column_result = gtk_tree_view_column_new_with_attributes(column_name_result,
                                       gtk_cell_renderer_text_new(), "text", 5, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(this->widget), column_result);

    gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(this->widget), GTK_TREE_VIEW_GRID_LINES_BOTH);

    g_signal_connect(this->widget, "row-activated", G_CALLBACK(OnRowActivated), NULL);

    return this->widget;
}

void GTreeViewDDResult::clear()
{
    GtkTreeModel* tree_model =  gtk_tree_view_get_model(GTK_TREE_VIEW(this->widget));
    gtk_list_store_clear(GTK_LIST_STORE(tree_model));
}

void GTreeViewDDResult::appendData(bool selected, const char* file_name, const char* file_path,
                                   const char* task_name, const char* dlp_name, const char* result)
{
    GtkTreeIter iter;
    GtkTreeModel* tree_model =  gtk_tree_view_get_model(GTK_TREE_VIEW(this->widget));
    gtk_list_store_append(GTK_LIST_STORE(tree_model), &iter);
    gtk_list_store_set(GTK_LIST_STORE(tree_model), &iter,
                       0, selected ? 1 : 0,
                       1, file_name,
                       2, file_path,
                       3, task_name,
                       4, dlp_name,
                       5, result,
                       -1);
}

void GTreeViewDDResult::OnRowActivated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer arg)
{
    GtkTreeSelection *selection = gtk_tree_view_get_selection(tree_view);
    int value = 0;
    GtkTreeIter iter;
    GtkTreeModel *tree_model;
    gtk_tree_selection_get_selected(selection, &tree_model, &iter);
    gtk_tree_model_get(tree_model, &iter, 0, &value, -1);
    if(value)
    {
        value = 0;
    }
    else
    {
        value = 1;
    }
    gtk_list_store_set(GTK_LIST_STORE(tree_model), &iter, 0, value, -1);
}


std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> GTreeViewDDResult::getAllTask()
{
    std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> list;

    GtkTreeIter iter;
    GtkTreeModel* tree_model =  gtk_tree_view_get_model(GTK_TREE_VIEW(this->widget));
    if(tree_model == NULL)
    {
        return list;
    }
    gboolean valid = gtk_tree_model_get_iter_first(tree_model, &iter);
    while(valid)
    {
        gint selected = 0;
        gchar* file_name = NULL;
        gchar* file_path = NULL;
        gchar* task_name = NULL;
        gchar* dlp_name = NULL;
        gchar* result = NULL;

        gtk_tree_model_get(tree_model, &iter,
                           0, &selected,
                           1, &file_name,
                           2, &file_path,
                           3, &task_name,
                           4, &dlp_name,
                           5, &result,
                           -1);

        DATA_DISCOVERY_TASK_RESULT_ITEM item;
        item.selected = selected;

        if(file_name != NULL)
        {
            item.file_name = file_name;
            g_free(file_name);
        }
        if(file_path != NULL)
        {
            item.file_path = file_path;
            g_free(file_path);
        }
        if(task_name != NULL)
        {
            item.task_name = task_name;
            g_free(task_name);
        }
        if(dlp_name != NULL)
        {
            item.dlp_name = dlp_name;
            g_free(dlp_name);
        }
        if(result != NULL)
        {
            item.result = result;
            g_free(result);
        }

        list.push_back(item);

        valid = gtk_tree_model_iter_next(tree_model, &iter);
    }

    return list;
}

std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> GTreeViewDDResult::getAllTaskSelected()
{
    std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> list = getAllTask();
    auto iter = list.begin();
    while(iter != list.end())
    {
        if(iter->selected == false)
        {
            iter = list.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return list;
}

std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> GTreeViewDDResult::getAllTaskUnSelected()
{
    std::vector<DATA_DISCOVERY_TASK_RESULT_ITEM> list = getAllTask();
    auto iter = list.begin();
    while(iter != list.end())
    {
        if(iter->selected == true)
        {
            iter = list.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return list;
}

