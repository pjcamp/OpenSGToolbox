/*---------------------------------------------------------------------------*\
 *                     OpenSG ToolBox UserInterface                          *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *   Authors: David Kabala, Alden Peterson, Lee Zaniewski, Jonathan Flory    *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

#ifndef _OSGABSTRACTTREELAYOUTCACHE_H_
#define _OSGABSTRACTTREELAYOUTCACHE_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "OSGUserInterfaceDef.h"

#include "OSGTreeRowMapper.h"
#include "Component/Tree/OSGTreePath.h"
#include "Component/Tree/Model/OSGTreeModel.h"
#include "Component/Tree/Model/OSGTreeModelEvent.h"
#include "Component/Tree/Selection/OSGTreeSelectionModel.h"
#include <OpenSG/OSGVector.h>

OSG_BEGIN_NAMESPACE

/*! \brief AbstractTreeLayoutCache class. See \ref 
           PageUserInterfaceAbstractTreeLayoutCache for a description.
*/

class OSG_USERINTERFACELIB_DLLMAPPING AbstractTreeLayoutCache : public TreeRowMapper
{
    /*==========================  PUBLIC  =================================*/
  public:
	//Returns the rows that the TreePath instances in path are being displayed at.
	virtual std::vector<UInt32> getRowsForPaths(std::vector<TreePath> path);

	//Returns a rectangle giving the bounds needed to draw path.
	virtual void getBounds(Pnt2s& TopLeft, Pnt2s& BottomRight, TreePath path, Pnt2s TopLeftPlaceIn, Pnt2s BottomRightPlaceIn) const = 0;

	//Returns true if the path is expanded, and visible.
	virtual bool getExpandedState(TreePath path) const const = 0;

	//Returns the TreeModel that is providing the data.
	virtual TreeModelPtr getModel(void) const;

	//Returns the object that renders nodes in the tree, and which is responsible for calculating the dimensions of individual nodes.
	//virtual AbstractLayoutCache.NodeDimensions getNodeDimensions(void) const;

	//Returns the path to the node that is closest to x,y.
	virtual TreePath getPathClosestTo(const UInt32& x, const UInt32& y) const = 0;

	//Returns the path for passed in row.
	virtual TreePath getPathForRow(const UInt32& row) const = 0;

	//Returns the preferred height.
	virtual UInt32 getPreferredHeight(void) const;

	//Returns the preferred width for the passed in region.
	virtual UInt32 getPreferredWidth(Pnt2s& TopLeft, Pnt2s& BottomRight) const;

	//Number of rows being displayed.
	virtual UInt32 getRowCount(void) const = 0;

	//Returns the row that the last item identified in path is visible at.
	virtual UInt32 getRowForPath(TreePath path) const = 0;

	//Returns the height of each row.
	virtual UInt32 getRowHeight(void) const;

	//Returns the rows that the TreePath instances in path are being displayed at.
	virtual std::vector<UInt32> getRowsForPaths(std::vector<TreePath> paths) const;

	//Returns the model used to maintain the selection.
	virtual TreeSelectionModelPtr getSelectionModel(void) const;

	//Returns the number of visible children for row.
	virtual UInt32 getVisibleChildCount(TreePath path) const = 0;

	//Returns an Enumerator that increments over the visible paths starting at the passed in location.
	//virtual Enumeration getVisiblePathsFrom(TreePath path) const = 0;

	//Instructs the LayoutCache that the bounds for path are invalid, and need to be updated.
	virtual void invalidatePathBounds(TreePath path) = 0;

	//Informs the TreeState that it needs to recalculate all the sizes it is referencing.
	virtual void invalidateSizes(void) = 0;

	//Returns true if the value identified by row is currently expanded.
	virtual bool isExpanded(TreePath path) const = 0;

	//Returns true if the root node of the tree is displayed.
	virtual bool isRootVisible(void) const;

	//Marks the path path expanded state to isExpanded.
	virtual void setExpandedState(TreePath path, bool isExpanded) = 0;

	//Sets the TreeModel that will provide the data.
	virtual void setModel(TreeModelPtr newModel);

	//Sets the renderer that is responsible for drawing nodes in the tree and which is threfore responsible for calculating the dimensions of individual nodes.
	//virtual void setNodeDimensions(AbstractLayoutCache.NodeDimensions nd);

	//Determines whether or not the root node from the TreeModel is visible.
	virtual void setRootVisible(bool rootVisible);

	//Sets the height of each cell.
	virtual void setRowHeight(const UInt32& rowHeight);

	//Sets the TreeSelectionModel used to manage the selection to new LSM.
	virtual void setSelectionModel(TreeSelectionModelPtr newLSM);

	//Invoked after a node (or a set of siblings) has changed in some way.
	virtual void treeNodesChanged(TreeModelEvent e) = 0;

	//Invoked after nodes have been inserted into the tree.
	virtual void treeNodesInserted(TreeModelEvent e) = 0;

	//Invoked after nodes have been removed from the tree.
	virtual void treeNodesRemoved(TreeModelEvent e) = 0;

	//Invoked after the tree has drastically changed structure from a given node down.
	virtual void treeStructureChanged(TreeModelEvent e) = 0;


  protected:
	//Returns, by reference in placeIn, the size needed to represent value.
	virtual void getNodeDimensions(Pnt2s& TopLeft, Pnt2s& BottomRight, SharedFieldPtr value, const UInt32& row, const UInt32& depth, bool expanded, Pnt2s TopLeftPlaceIn, Pnt2s BottomRightPlaceIn);


	//Returns true if the height of each row is a fixed size.
	virtual bool isFixedRowHeight(void) const;

    //Object responsible for getting the size of a node.
    //AbstractLayoutCache.NodeDimensions nodeDimensions;

    //True if the root node is displayed, false if its children are the highest visible nodes.
    bool _RootVisible;

    //Height to use for each row.
    Int32 _RowHeight;

    //Model providing information.
    TreeModelPtr _TreeModel;

    //Selection model.
    TreeSelectionModelPtr _TreeSelectionModel;

    /*==========================  PRIVATE  ================================*/
  private:
};

typedef AbstractTreeLayoutCache *AbstractTreeLayoutCachePtr;

OSG_END_NAMESPACE

#define OSGABSTRACTTREELAYOUTCACHE_HEADER_CVSID "@(#)$Id: FCTemplate_h.h,v 1.23 2005/03/05 11:27:26 dirk Exp $"

#endif /* _OSGABSTRACTTREELAYOUTCACHE_H_ */
