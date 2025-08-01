#pragma execution_character_set("utf-8")












#ifndef OPTIMIZER_H_
#define OPTIMIZER_H_
#include "config.hpp"
#include "field-math.hpp"
#include "hierarchy.hpp"

namespace qflow {

class  Optimizer {
   public:
    Optimizer();
    static void optimize_orientations(Hierarchy& mRes);
    static void optimize_scale(Hierarchy& mRes, VectorXd& rho, int adaptive);
    static void optimize_positions(Hierarchy& mRes, int with_scale = 0);
    static void optimize_integer_constraints(Hierarchy& mRes, std::map<int, int>& singularities,
                                             bool use_minimum_cost_flow);
    static void optimize_positions_fixed(
        Hierarchy& mRes, std::vector<DEdge>& edge_values, std::vector<Vector2i>& edge_diff,
        std::set<int>& sharp_vertices,
        std::map<int, std::pair<Vector3d, Vector3d>>& sharp_constraints,
        std::vector<int>& sharp_edges, std::set<int>& Boundary_vertices,
        std::map<int, std::pair<Vector3d, Vector3d>>& Boundary_constraints,
        std::vector<int>& Boundary_edges, int with_scale = 0);
    static void optimize_positions_sharp(
        Hierarchy& mRes, std::vector<DEdge>& edge_values, std::vector<Vector2i>& edge_diff,
        std::vector<int>& sharp_edges, std::set<int>& sharp_vertices,
        std::map<int, std::pair<Vector3d, Vector3d>>& sharp_constraints,
        std::vector<int>& Boundary_edges, std::set<int>& Boundary_vertices,
        std::map<int, std::pair<Vector3d, Vector3d>>& Boundary_constraints, int with_scale = 0);
    static void optimize_positions_dynamic(
        Hierarchy&mRes, MatrixXi& F, MatrixXd& V, MatrixXd& N, MatrixXd& Q,
        std::vector<std::vector<int>>& Vset,
        std::vector<Vector3d>& O_compact, std::vector<Vector4i>& F_compact,
        std::vector<int>& V2E_compact, std::vector<int>& E2E_compact, double mScale,
        std::vector<Vector3d>& diffs, std::vector<int>& diff_count,
        std::map<std::pair<int, int>, int>& o2e, std::vector<int>& sharp_o,
        std::map<int, std::pair<Vector3d, Vector3d>>& compact_sharp_constraints,
        std::vector<int>& boundary_o, std::map<int, std::pair<Vector3d, Vector3d>>& compact_boundary_constraints);
    static void extract_patch(
        Hierarchy& mRes, MatrixXi& F, MatrixXd& V, MatrixXd& N, MatrixXd& Q,
        std::vector<std::vector<int>>& Vset, std::vector<Vector3d>& O_compact,
        std::vector<Vector4i>& F_compact, std::vector<int>& V2E_compact,
        std::vector<int>& E2E_compact, double mScale, std::vector<Vector3d>& diffs,
        std::vector<int>& diff_count, std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<int>& sharp_o,
        std::map<int, std::pair<Vector3d, Vector3d>>& compact_sharp_constraints,
        std::vector<int>& boundary_o,
        std::map<int, std::pair<Vector3d, Vector3d>>& compact_boundary_constraints);



    static void size_three(std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<Vector3d>& O_compact, std::vector<int>& all_singularity,
        std::vector<std::vector<std::vector<int>>>& collapse_patch,
        std::vector<int>& boundary_o);

    static void sin_fft_boundary(std::vector<Vector3d>& O_compact, std::vector<int> boundary_o,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<int>& valence,
        std::vector<std::vector<std::vector<int>>>& relative_point,
        std::vector<std::vector<int>>& layer,
        std::vector<std::vector<std::vector<int>>>& collapse_patch, int v,
        std::vector<int>& all_singularity,
        std::vector<int>& thr_for_sin_patch);

    static void sin_fft(std::vector<Vector3d>& O_compact,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<int>& valence,
        std::vector<std::vector<std::vector<int>>>& relative_point,
        std::vector<std::vector<int>>& layer,
        std::vector<std::vector<std::vector<int>>>& collapse_patch, int v,
        std::vector<int>& all_singularity, std::vector<int>& thr_for_sin_patch);

    static void sin_ftt(std::vector<Vector3d>& O_compact,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<int>& valence,
        std::vector<std::vector<std::vector<int>>>& relative_point,
        std::vector<std::vector<int>>& layer,
        std::vector<std::vector<std::vector<int>>>& collapse_patch, int v,
        std::vector<int>& all_singularity, std::vector<int>& thr_for_sin_patch);

    static void sin_ft(std::vector<Vector3d>& O_compact,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<int>& valence,
        std::vector<std::vector<std::vector<int>>>& relative_point,
        std::vector<std::vector<int>>& layer,
        std::vector<std::vector<std::vector<int>>>& collapse_patch, int v, int v1,
        int v2, std::vector<int>& all_singularity,
        std::vector<int>& thr_for_sin_patch);

    static void match_patch(int i, int j, int v, std::vector<int>& edge_collapse,
        std::vector<std::vector<std::vector<int>>>& collapse_patch,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<std::vector<std::vector<int>>>& assist_patch,
        std::vector<int>& can, std::vector<int>& relative_can,
        std::vector<int>& relative_double, std::vector<int>& double_following,
        std::vector<int>& thenum, std ::vector<int>& renew);

    static void update_O(std::vector<Vector3d>& O_compact,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<int>& all_singularity, std::vector<int>& boundary_o);

    static void sin_mismatching(std::vector<std::vector<int>>& need_collapse_part,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<Vector3d>& O_compact,
        std::vector<std::vector<std::vector<int>>>& relative_point,
        std::vector<std::vector<int>>& layer,
        std::vector<int>& need_collapse, std::vector<int>& all_singularity,
        std::vector<std::vector<std::vector<int>>>& collapse_patch, int n,
        std::vector<std::vector<int>>& double_q,
        std::vector<int>& boundary_o);

    static void collapse_boundary(std::vector<Vector3d>& O_compact,
        std::vector<std::vector<std::vector<int>>>& patch_compact,
        std::vector<int>& valence,
        std::vector<std::vector<std::vector<int>>>& relative_point,
        std::vector<std::vector<int>>& layer,
        std::vector<std::vector<std::vector<int>>>& collapse_patch,
        std::vector<int>& all_singularity);


#ifdef WITH_CUDA
    static void optimize_orientations_cuda(Hierarchy& mRes);
    static void optimize_positions_cuda(Hierarchy& mRes);
#endif
};

#ifdef WITH_CUDA
extern void UpdateOrientation(int* phase, int num_phases, glm::dvec3* N, glm::dvec3* Q, Link* adj,
                              int* adjOffset, int num_adj);
extern void PropagateOrientationUpper(glm::dvec3* srcField, int num_orientation,
                                      glm::ivec2* toUpper, glm::dvec3* N, glm::dvec3* destField);
extern void PropagateOrientationLower(glm::ivec2* toUpper, glm::dvec3* Q, glm::dvec3* N,
                                      glm::dvec3* Q_next, glm::dvec3* N_next, int num_toUpper);

extern void UpdatePosition(int* phase, int num_phases, glm::dvec3* N, glm::dvec3* Q, Link* adj,
                           int* adjOffset, int num_adj, glm::dvec3* V, glm::dvec3* O,
                           double scale);
extern void PropagatePositionUpper(glm::dvec3* srcField, int num_position, glm::ivec2* toUpper,
                                   glm::dvec3* N, glm::dvec3* V, glm::dvec3* destField);

#endif

} // namespace qflow

#endif
