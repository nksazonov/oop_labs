#ifndef MOVIETOSEEMODEL_H
#define MOVIETOSEEMODEL_H

#include "../dataDef/movieToSee.h"

#include <QAbstractTableModel>
#include <vector>

class MovieToSeeModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit MovieToSeeModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    void sort(int column, Qt::SortOrder order) override;
public:
    void addMovie(const MovieToSee& movie);

private:
    std::vector<MovieToSee> moviesToSee;

};

#endif // MOVIETOSEEMODEL_H