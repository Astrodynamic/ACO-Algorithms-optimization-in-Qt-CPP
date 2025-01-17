#ifndef ANT_COLONY_OPTIMIZATION_ALGORITHM_GRAPH_GRAPH_H_
#define ANT_COLONY_OPTIMIZATION_ALGORITHM_GRAPH_GRAPH_H_

#include <fstream>
#include <iostream>
#include <random>
#include <string>

class Graph {
 public:
  Graph();
  explicit Graph(unsigned dimension);
  Graph(Graph& graph);
  ~Graph();

  bool LoadGraphFromFile(std::string filename);
  bool LoadGraphToFile(std::string filename) const;
  bool ExportGraphToDot(std::string filename) const;

  unsigned GetDimension() const;
  void SetDimension(const unsigned dimension);

  void Fill(double value);
  void Generate(const unsigned dimension);

  double& operator()(const unsigned row, const unsigned col);
  const double& operator()(const unsigned row, const unsigned col) const;

  Graph& operator*=(const double value);
  Graph& operator=(const Graph& other);

 private:
  double** m_matrix;
  unsigned m_dimension;

  static constexpr double min_random_value = +0.0;
  static constexpr double max_random_value = +10'000.0;

  static std::random_device rd;
  static std::default_random_engine generator;
  static std::uniform_real_distribution<double> distribution;

  void InitMatrix(unsigned dimension);
  void DestroyMatrix();
};

#endif  // ANT_COLONY_OPTIMIZATION_ALGORITHM_GRAPH_GRAPH_H_